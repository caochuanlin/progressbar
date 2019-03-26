
#include "CProgressBar.h"

namespace LSV
{
	CProgressBar::CProgressBar( QWidget *parent /*= 0*/ ) : QProgressBar(parent)
	{
		this->setStyleSheet(
			"QProgressBar {color:black;font-size:12px;font-weight:normal;font-family:'Microsoft YaHei'; text-align:center; }"
			"QProgressBar::chunk {background-color: rgb(0, 160, 244);}");
	}

	void CProgressBar::ShowTips( const QString& strTips )
	{
		if (this->isHidden())
		{
			this->show();
		}

		this->resetFormat();
		this->setRange(0,100);
		this->setFormat(strTips);
		this->setValue(100);
	}

	double CProgressBar::GetDoubleFormatValue()
	{
		double dValue = 0.0;

		QString strFormat = this->format();
		if (!strFormat.isEmpty())
		{
			int nIndex = strFormat.indexOf(":");
			if (nIndex != -1)
			{
				QString strFormatData = strFormat.mid(nIndex+1,strFormat.length()-nIndex-2);
				dValue = strFormatData.toDouble();
			}
		}

		return dValue;
	}

	void CProgressBar::SetDoubleFormatValue( const QString& strFormat,double dValue )
	{
		if (this->isHidden())
		{
			this->show();
		}

		this->setFormat(strFormat + ":" + QString::number(dValue, 'f', 2) + "%");
		this->setValue(dValue);
	}


}
