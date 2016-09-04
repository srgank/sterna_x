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

    QStringList Get_Priemnica_HeaderState(){return priemnica_HeaderState;}
    void Set_Priemnica_HeaderState(QStringList temp_priemnica_HeaderState){priemnica_HeaderState = temp_priemnica_HeaderState;}

    QStringList Get_PriemnicaDetail_HeaderState(){return priemnicaDetail__HeaderState;}
    void Set_PriemnicaDetail_HeaderState(QStringList temp_priemnicaDetail_HeaderState){priemnicaDetail__HeaderState = temp_priemnicaDetail_HeaderState;}

    QStringList Get_Ispratnica_HeaderState(){return ispratnica_HeaderState;}
    void Set_Ispratnica_HeaderState(QStringList temp_ispratnica_HeaderState){ispratnica_HeaderState = temp_ispratnica_HeaderState;}

    QStringList Get_IspratnicaDetail_HeaderState(){return ispratnicaDetail__HeaderState;}
    void Set_IspratnicaDetail_HeaderState(QStringList temp_ispratnicaDetail_HeaderState){ispratnicaDetail__HeaderState = temp_ispratnicaDetail_HeaderState;}

    QStringList Get_Povratnica_HeaderState(){return povratnica_HeaderState;}
    void Set_Povratnica_HeaderState(QStringList temp_povratnica_HeaderState){povratnica_HeaderState = temp_povratnica_HeaderState;}

    QStringList Get_PovratnicaDetail_HeaderState(){return povratnicaDetail__HeaderState;}
    void Set_PovratnicaDetail_HeaderState(QStringList temp_povratnicaDetail_HeaderState){povratnicaDetail__HeaderState = temp_povratnicaDetail_HeaderState;}

    QStringList Get_Faktura_HeaderState(){return faktura_HeaderState;}
    void Set_Faktura_HeaderState(QStringList temp_faktura_HeaderState){faktura_HeaderState = temp_faktura_HeaderState;}

    QStringList Get_FakturaDetail_HeaderState(){return fakturaDetail__HeaderState;}
    void Set_FakturaDetail_HeaderState(QStringList temp_FakturaDetail_HeaderState){fakturaDetail__HeaderState = temp_FakturaDetail_HeaderState;}


    QStringList Get_ProFaktura_HeaderState(){return profaktura_HeaderState;}
    void Set_ProFaktura_HeaderState(QStringList temp_profaktura_HeaderState){profaktura_HeaderState = temp_profaktura_HeaderState;}

    QStringList Get_ProFakturaDetail_HeaderState(){return profakturaDetail__HeaderState;}
    void Set_ProFakturaDetail_HeaderState(QStringList temp_ProFakturaDetail_HeaderState){profakturaDetail__HeaderState = temp_ProFakturaDetail_HeaderState;}

    QStringList Get_Naracka_HeaderState(){return naracka_HeaderState;}
    void Set_Naracka_HeaderState(QStringList temp_naracka_HeaderState){naracka_HeaderState = temp_naracka_HeaderState;}

    QStringList Get_NarackaDetail_HeaderState(){return narackaDetail__HeaderState;}
    void Set_NarackaDetail_HeaderState(QStringList temp_NarackaDetail_HeaderState){narackaDetail__HeaderState = temp_NarackaDetail_HeaderState;}

    QStringList Get_Nalog_HeaderState(){return nalog_HeaderState;}
    void Set_Nalog_HeaderState(QStringList temp_Nalog_HeaderState){nalog_HeaderState = temp_Nalog_HeaderState;}

    QStringList Get_NalogDetail_HeaderState(){return nalogDetail__HeaderState;}
    void Set_NalogDetail_HeaderState(QStringList temp_NalogDetail_HeaderState){nalogDetail__HeaderState = temp_NalogDetail_HeaderState;}

    QStringList Get_Smetka_HeaderState(){return smetka_HeaderState;}
    void Set_Smetka_HeaderState(QStringList temp_Smetka_HeaderState){smetka_HeaderState = temp_Smetka_HeaderState;}

    QStringList Get_SmetkaDetail_HeaderState(){return smetkaDetail__HeaderState;}
    void Set_SmetkaDetail_HeaderState(QStringList temp_SmetkaDetail_HeaderState){smetkaDetail__HeaderState = temp_SmetkaDetail_HeaderState;}



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

    QStringList priemnica_HeaderState;
    QStringList priemnicaDetail__HeaderState;

    QStringList ispratnica_HeaderState;
    QStringList ispratnicaDetail__HeaderState;

    QStringList povratnica_HeaderState;
    QStringList povratnicaDetail__HeaderState;

    QStringList faktura_HeaderState;
    QStringList fakturaDetail__HeaderState;

    QStringList profaktura_HeaderState;
    QStringList profakturaDetail__HeaderState;

    QStringList nalog_HeaderState;
    QStringList nalogDetail__HeaderState;

    QStringList naracka_HeaderState;
    QStringList narackaDetail__HeaderState;

    QStringList smetka_HeaderState;
    QStringList smetkaDetail__HeaderState;

    QString urlhost;
};
#endif // Singleton_H
