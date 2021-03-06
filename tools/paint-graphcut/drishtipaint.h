#ifndef DRISHTIPAINT_H
#define DRISHTIPAINT_H

#include <QtGui>
#include "ui_drishtipaint.h"

#include "tagcoloreditor.h"
#include "transferfunctionmanager.h"
#include "transferfunctioneditorwidget.h"
#include "imagewidget.h"
#include "myslider.h"
#include "volume.h"

class DrishtiPaint : public QMainWindow
{
  Q_OBJECT

 public :
  DrishtiPaint(QWidget *parent=0);

 protected :
  void dragEnterEvent(QDragEnterEvent*);
  void dropEvent(QDropEvent*);
  void closeEvent(QCloseEvent*);
  void keyPressEvent(QKeyEvent*);

 private slots :
  void openRecentFile();   
  void on_actionHelp_triggered();
  void on_saveImage_triggered();
  void on_actionLoad_triggered();
  void on_actionExit_triggered();
  void on_actionExtractTag_triggered();
  void on_butZ_clicked();
  void on_butY_clicked();
  void on_butX_clicked();
  void on_tag_valueChanged(int);
  void on_boxSize_valueChanged(int);
  void on_lambda_valueChanged(int);
  void on_preverode_valueChanged(int);
  void on_smooth_valueChanged(int);
  void on_copyprev_clicked();
  void changeTransferFunctionDisplay(int, QList<bool>);
  void checkStateChanged(int, int, bool);
  void updateComposite();
  void getSlice(int);
  void getMaskSlice(int);
  void getRawValue(int, int, int);
  void tagDSlice(int, QImage);
  void tagWSlice(int, QImage);
  void tagHSlice(int, QImage);
  void tagDSlice(int, uchar*);
  void tagWSlice(int, uchar*);
  void tagHSlice(int, uchar*);
  void fillVolume(int, int,
		  int, int,
		  int, int,
		  QList<int>,
		  bool);
  void tagAllVisible(int, int,
		     int, int,
		     int, int);
  void dilate();
  void dilate(int, int,
	      int, int,
	      int, int);
  void erode();
  void erode(int, int,
	     int, int,
	     int, int);

  void applyMaskOperation(int, int, int);

 private :
  Ui::DrishtiPaint ui;

  TagColorEditor *m_tagColorEditor;

  TransferFunctionContainer *m_tfContainer;
  TransferFunctionManager *m_tfManager;
  TransferFunctionEditorWidget *m_tfEditor;

  ImageWidget *m_imageWidget;
  MySlider *m_slider;
  Volume *m_volume;
  BitmapThread *m_bitmapThread;

  int m_currSlice;

  QString m_pvlFile;
  QString m_xmlFile;

  QList <QAction*> m_recentFileActions;

  void setFile(QString);
  void initTagColors();

  void loadSettings();
  void saveSettings();

  void updateRecentFileAction();
  QString loadVolumeFromProject(const char*);

  void sliceDilate(int, int, uchar*, uchar*, int, int);
  void dilate(int, int, uchar**, uchar*, int, int);

  void sliceErode(int, int, uchar*, uchar*, int, int);
  void erode(int, int, uchar**, uchar*, int, int);

  void sliceSmooth(int, int, uchar*, uchar*, int, int, int);
  void smooth(int, int, uchar**, uchar*, int, int, int);

  void savePvlHeader(QString, QString, int, int, int, bool);
};

#endif
