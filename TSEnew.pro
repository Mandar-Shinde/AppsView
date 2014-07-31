HEADERS     = AppViewer.h \
				PLog.h \ 
			  FileDownload.h
SOURCES     = main.cpp \
             AppViewer.cpp \
             PLog.cpp \ 
			  FileDownload.cpp

FORMS += TSEApps.ui

QT += network core gui
RESOURCES += resources.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/layouts/borderlayout
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/layouts/borderlayout
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
