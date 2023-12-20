'''import tkinter as tk
from tkinter import filedialog

import cv2 as cv
print( cv.__version__ )
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image, ImageTk


class ImageProcessor:

    def __init__(self) -> None:

        self.root = tk.Tk()
        self.root.title("Image processor")

        self.default_image = np.zeros((300, 300, 3), dtype=np.uint8)
        self.default_image[:] = (255, 255, 255)

        self.image = None
        self.processed_image = None
        self.panel = tk.Label(self.root)
        self.panel.pack(side="left", padx=10, pady=7)

        self._setup_buttons()


    def _setup_buttons(self) -> None:

        self.open_btn = tk.Button(
            self.root, text="Open Image", command=self.open_image
        )
        self.open_btn.pack(pady=7)

        self.original_btn = tk.Button(
            self.root, text="Show Original", command=self.show_original_image
        )
        self.original_btn.pack(pady=7)

        self.points_btn = tk.Button(
            self.root, text="Show Points", command=self.show_points
        )
        self.points_btn.pack(pady=7)

        self.gradient_btn = tk.Button(
            self.root, text="Show Gradient Magnitude", command=self.show_gradient_magnitude
        )
        self.gradient_btn.pack(pady=7)

        self.edges_btn = tk.Button(
            self.root, text="Show Edges", command=self.show_edges
        )
        self.edges_btn.pack(pady=7)

        self.histogram_btn = tk.Button(
            self.root, text="Show Histogram", command=self.show_histogram
        )
        self.histogram_btn.pack(pady=7)

        self.linear_contrast_btn = tk.Button(
            self.root, text="Linear Contrast", command=self.linear_contrast
        )
        self.linear_contrast_btn.pack(pady=7)

        self.histogram_equalization_btn = tk.Button(
            self.root, text="Histogram Equalization", command=self.histogram_equalization
        )
        self.histogram_equalization_btn.pack(pady=7)

        self.rgb_histogram_equalization_btn = tk.Button(
            self.root, text="RGB Histogram Equalization", command=self.rgb_histogram_equalization
        )
        self.rgb_histogram_equalization_btn.pack(pady=7)

        self.hsv_histogram_equalization_btn = tk.Button(
            self.root, text="HSV Histogram Equalization", command=self.hsv_histogram_equalization
        )
        self.hsv_histogram_equalization_btn.pack(pady=7)


    def resize_image(self, image, width=None, height=None):
        h, w = image.shape[:2]

        if width is None and height is None:
            return image

        if width is None:
            aspect_ratio = height / h
            new_width = int(w * aspect_ratio)
            new_size = (new_width, height)
        else:
            aspect_ratio = width / w
            new_height = int(h * aspect_ratio)
            new_size = (width, new_height)

        resized_img = cv.resize(image, new_size, interpolation=cv.INTER_AREA)
        return resized_img


    def open_image(self):
        file_path = filedialog.askopenfilename()

        if file_path:
            self.image = cv.imread(file_path)
            self.processed_image = np.copy(self.image)
            self.display_image(self.processed_image)
        else:
            self.image = None
            self.processed_image = None
            self.display_image(self.default_image)


    def show_original_image(self):
        if self.image is None:
            return
        self.processed_image = np.copy(self.image)
        self.display_image(self.processed_image)


    def show_points(self):
        if self.image is None:
            return

        gray = cv.cvtColor(self.image, cv.COLOR_BGR2GRAY)
        edges = cv.Canny(gray, threshold1=50, threshold2=150, apertureSize=3)

        sobelx = cv.Sobel(gray, cv.CV_64F, 1, 0, ksize=5)
        sobely = cv.Sobel(gray, cv.CV_64F, 0, 1, ksize=5)

        gradient_magnitude = cv.magnitude(sobelx, sobely)
        gradient_magnitude = cv.normalize(gradient_magnitude, None, 0, 255, cv.NORM_MINMAX).astype(np.uint8)

        all_points = cv.bitwise_or(edges, gradient_magnitude)
        self.display_image(all_points)


    def show_gradient_magnitude(self):
        if self.image is None:
            return

        gray = cv.cvtColor(self.image, cv.COLOR_BGR2GRAY)

        sobelx = cv.Sobel(gray, cv.CV_64F, 1, 0, ksize=5)
        sobely = cv.Sobel(gray, cv.CV_64F, 0, 1, ksize=5)

        gradient_magnitude = cv.magnitude(sobelx, sobely)
        gradient_magnitude = cv.normalize(gradient_magnitude, None, 0, 255, cv.NORM_MINMAX).astype(np.uint8)
        self.display_image(gradient_magnitude)


    def show_edges(self):
        if self.image is None:
            return
        gray = cv.cvtColor(self.image, cv.COLOR_BGR2GRAY)
        edges = cv.Canny(gray, threshold1=50, threshold2=150, apertureSize=3)
        self.display_image(edges)


    def display_image(self, img):
        img = self.resize_image(img, width=650, height=650)
        img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
        img = Image.fromarray(img)
        img = ImageTk.PhotoImage(image=img)
        self.panel.config(image=img)
        self.panel.image = img


    def show_histogram(self) -> None:
        if self.image is None:
            return

        gray = cv.cvtColor(self.image, cv.COLOR_BGR2GRAY)
        hist = cv.calcHist([gray], [0], None, [256], [0, 256])

        plt.plot(hist)
        plt.title("Grayscale Histogram")
        plt.xlabel("Bins")
        plt.ylabel("# of Pixels")
        plt.show()


    def linear_contrast(self) -> None:
        if self.image is None:
            return
        alpha = 1.5
        beta = 30
        self.processed_image = cv.convertScaleAbs(self.image, alpha=alpha, beta=beta)
        self.display_image(self.processed_image)

    def histogram_equalization(self) -> None:
        if self.image is None:
            return
        gray = cv.cvtColor(self.image, cv.COLOR_BGR2GRAY)
        equalized = cv.equalizeHist(gray)
        self.processed_image = cv.cvtColor(equalized, cv.COLOR_GRAY2BGR)
        self.display_image(self.processed_image)


    def rgb_histogram_equalization(self) -> None:
        if self.image is None:
            return

        b, g, r = cv.split(self.image)
        b_equalized = cv.equalizeHist(b)
        g_equalized = cv.equalizeHist(g)
        r_equalized = cv.equalizeHist(r)

        equalized_image = cv.merge((b_equalized, g_equalized, r_equalized))
        self.processed_image = equalized_image
        self.display_image(self.processed_image)


    def hsv_histogram_equalization(self) -> None:
        if self.image is None:
            return

        hsv = cv.cvtColor(self.image, cv.COLOR_BGR2HSV)
        h, s, v = cv.split(hsv)
        v_equalized = cv.equalizeHist(v)
        hsv_equalized = cv.merge((h, s, v_equalized))
        equalized_image = cv.cvtColor(hsv_equalized, cv.COLOR_HSV2BGR)
        self.processed_image = equalized_image
        self.display_image(self.processed_image)

    def run(self) -> None:
        self.display_image(self.default_image)
        self.root.mainloop()


def main() -> None:
    processor = ImageProcessor()
    processor.run()
 

if __name__ == "__main__":
    main()
    '''
    
    
import numpy as np
import cv2 as cv
import imutils
from tkinter import ttk
from tkinter import *
from scipy import ndimage as ndi
from skimage.filters import edges
from skimage.feature import peak_local_max
from skimage.segmentation import watershed
from PIL import ImageTk, Image
from copy import deepcopy

class MainSolution():
    def __init__(self):
        self.image = cv.imread("coins.jpg")
        self.imgray = None
        self.trsh1 = None
        self.trsh2 = None

    def filt(self):
        self.imgray = cv.cvtColor(cv.pyrMeanShiftFiltering(
            self.image, 15, 50), cv.COLOR_BGR2GRAY)
        img = Image.fromarray(self.imgray)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def global_threshold(self):
      ret, thresh1 = cv.threshold(self.imgray, 0, 255, cv.THRESH_BINARY_INV | cv.THRESH_OTSU)
      self.trsh1 = deepcopy(thresh1)
      img = Image.fromarray(thresh1)
      img = img.resize((300, 300))
      return ImageTk.PhotoImage(img)

    def adaptive_threshold(self):
      thresh2 = cv.adaptiveThreshold(self.imgray, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 11, 2)
      self.trsh2 = deepcopy(thresh2)
      img = Image.fromarray(thresh2)
      img = img.resize((300, 300))
      return ImageTk.PhotoImage(img)
    
    def segmentation(self):
      dist = ndi.distance_transform_edt(self.trsh1)
      local_max = peak_local_max(dist, indices=False, min_distance=20, labels=self.trsh1)
      markers = ndi.label(local_max, structure=np.ones((3, 3)))[0]
      labels = watershed(-dist, markers, mask=self.trsh1)
      for label in np.unique(labels):
        if label == 0:
          continue
        mask = np.zeros(self.imgray.shape, dtype="uint8")
        mask[labels == label] = 255
        contours = cv.findContours(mask.copy(), cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
        contours = imutils.grab_contours(contours)
        c = max(contours, key=cv.contourArea)

        ((x, y), r) = cv.minEnclosingCircle(c)
        cv.circle(self.image, (int(x), int(y)), int(r), (255, 0, 0), 7)

      self.image = Image.fromarray(self.image)
      self.image = self.image.resize((300, 300))
      return ImageTk.PhotoImage(self.image)

if __name__ == "__main__":
    root = Tk()
    ms = MainSolution()
    w, h = root.winfo_screenwidth(), root.winfo_screenheight()
    root.geometry(f"700x700")
    lbl_text1 = ttk.Label(text="Глобальная пороговая обработка")
    lbl_text1.place(x=250, y=10)
    img1 = ms.filt()
    lbl1 = ttk.Label(image=img1)
    lbl1.image = img1
    lbl1.place(x=30, y=40, width=300, height=300)
    img2 = ms.global_threshold()
    lbl2 = ttk.Label(image=img2)
    lbl2.image = img2
    lbl2.place(x=370, y=40, width=300, height=300)
    lbl_text2 = ttk.Label(text="Адаптивная пороговая обработка")
    lbl_text2.place(x=90, y=360)
    img3 = ms.adaptive_threshold()
    lbl3 = ttk.Label(image=img3)
    lbl3.image = img3
    lbl3.place(x=30, y=390, width=300, height=300)
    lbl_text3 = ttk.Label(text="Сегментация")
    lbl_text3.place(x=480, y=360)
    img4 = ms.segmentation()
    lbl4 = ttk.Label(image=img4)
    lbl4.image = img4
    lbl4.place(x=370, y=390, width=300, height=300)
    root.mainloop()




