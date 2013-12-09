// MedianBlur.cpp

#include "MedianBlur.h"
#include "Conversion.h"
#include "Exception.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void MedianBlur::Initialize() { }

void MedianBlur::Draw(QImage &image, const QMap<QString, QString> &args)
{
	int ksize = 7;
	auto it = args.find("KernelSize");

	if (it != args.end() && it.key() == "KernelSize") {
		bool ok = false;
		ksize = it.value().toInt(&ok);

		if (!ok) {
			throw FormatException("couldn't convert \"KernelSize\" argument for median blur");
		} else if (ksize % 2 == 0 || ksize < 3) {
			throw ArgumentException("\"KernelSize\" argument for median blur must be odd and greater than 1");
		}
	}

	cv::Mat mat = QimageToMat(image, image.format());
	cv::medianBlur(mat.clone(), mat, ksize);
	image = MatToQimage(mat);
}

void MedianBlur::Finalize() { }