import os
from pdf2jpg import pdf2jpg
from imgaug import augmenters as iaa
from PIL import Image
from numpy import asarray
import inspect

filename = inspect.getframeinfo(inspect.currentframe()).filename
path = os.path.dirname(os.path.abspath(filename))

pdf_to_jpg = pdf2jpg.convert_pdf2jpg(path + r"\sample.pdf", path, pages="ALL")

seq = iaa.Sequential([
    iaa.AdditiveGaussianNoise(loc=0, scale=(0.2*255, 0.5*255), per_channel=True),
    iaa.Fliplr(0.5),
    iaa.GaussianBlur(sigma=(0, 10))
])

aug_imges = []
for file in pdf_to_jpg[0]['output_jpgfiles']:
    image = asarray(Image.open(file))
    images_aug = seq(image=image)
    aug_imges.append(Image.fromarray(images_aug))

aug_imges[0].save("aug_images.tiff", compression="tiff_deflate", save_all=True, append_images=aug_imges[1:])