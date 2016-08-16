#ifndef Singleton_H
#define Singleton_H

#include <QDateTime>

#include <QStringList>
#include <QRect>
#include <vector>


class Singleton 
{
public: 
//	typedef struct
//	{
//		QDateTime fakturaData;
//		QDateTime fakturaValuta;
//		float iznos;
//		float plateno;
//		QString komintent_naziv;
//		QString komintent_id;
//	} tinfoFakturi;

//    typedef std::vector<tinfoFakturi> tListInfoFakturi;
    static Singleton* Instance();
	int getUserID(){return m_user_id;}
	void setUserID(int userID){ m_user_id = userID;}
	QStringList getUserInfo(){return m_infoVraboten;}
	void setUserInfo(QStringList infoVraboten){ m_infoVraboten = infoVraboten;}
//	tListInfoFakturi m_listFakturiS;
    QRect getMainRect(){return m_rect;}
    void setMainRect(QRect t_rect){ m_rect = t_rect;}


    int getGlobalFontSize(){return globalFontSize;}
    void setGlobalFontSize(int eFontSize){globalFontSize = eFontSize;}

    int getGlobalFontSizeHeight(){return globalFontSizeHeight;}
    void setGlobalFontSizeHeight(int eFontSizeHeight){globalFontSizeHeight = eFontSizeHeight;}

    QStringList Get_Art_HeaderState(){return art_HeaderState;}
    void Set_Art_HeaderState(QStringList temp_art_HeaderState){art_HeaderState = temp_art_HeaderState;}

    QStringList Get_Kom_HeaderState(){return kom_HeaderState;}
    void Set_Kom_HeaderState(QStringList temp_kom_HeaderState){kom_HeaderState = temp_kom_HeaderState;}

//    QString Get_UrlHost(){QString urlhost = "http://92.53.51.86:5002/";return urlhost;}
    void Set_UrlHost(QString temp_urlhost){urlhost = temp_urlhost;}
    QString Get_UrlHost(){return urlhost;}




protected: 
	//Singleton();
private:
    QRect m_rect;
    int m_user_id;
	QStringList m_infoVraboten;
	static Singleton* _instance;
    QStringList m_colWidth;
    QStringList m_colWidth_k;
    int globalFontSize;
    int globalFontSizeHeight;

    QStringList art_HeaderState;
    QStringList kom_HeaderState;
    QString urlhost;
};
#endif // Singleton_H
