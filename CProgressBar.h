#ifndef C_PROGRESSBAR_H_
#define C_PROGRESSBAR_H_

#include <QtWidgets/QProgressBar>

namespace LSV
{
	class CProgressBar: public QProgressBar
	{
		Q_OBJECT

	public:
		CProgressBar(QWidget *parent = 0);
		~CProgressBar() {}

	public:
		void ShowTips(const QString& strTips);

		void SetDoubleFormatValue(const QString& strFormat,double dValue);

		double GetDoubleFormatValue();


	};
}

#endif
