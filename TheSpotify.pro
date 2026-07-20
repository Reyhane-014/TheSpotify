QT       += core widgets multimedia

TARGET = TheSpotify
TEMPLATE = app

SOURCES += \
    GUI/editaccountwindow.cpp \
    GUI/editsongdialog.cpp \
    GUI/playercontrol.cpp \
    main.cpp \
    GUI/loginwindow.cpp \
    GUI/registerwindow.cpp \
    GUI/artistdashboard.cpp \
    GUI/listenerdashboard.cpp \
    Sources/services/authmanager.cpp \
    Sources/services/artisthandler.cpp \
    Sources/services/listenerhandler.cpp \
    Sources/repositories/accountmanager.cpp \
    Sources/repositories/artistmanager.cpp \
    Sources/repositories/listenermanager.cpp \
    Sources/repositories/albummanager.cpp \
    Sources/repositories/playlistmanager.cpp \
    Sources/repositories/songmanager.cpp \
    Sources/repositories/datamanager.cpp \
    Sources/utils/filehelper.cpp \
    Sources/entities/account.cpp \
    Sources/entities/artist.cpp \
    Sources/entities/listener.cpp \
    Sources/entities/album.cpp \
    Sources/entities/playlist.cpp \
    Sources/entities/song.cpp

HEADERS += \
    GUI/editaccountwindow.h \
    GUI/editsongdialog.h \
    GUI/playercontrol.h \
    GUI/loginwindow.h \
    GUI/registerwindow.h \
    GUI/artistdashboard.h \
    GUI/listenerdashboard.h \
    Sources/services/authmanager.h \
    Sources/services/artisthandler.h \
    Sources/services/listenerhandler.h \
    Sources/repositories/accountmanager.h \
    Sources/repositories/artistmanager.h \
    Sources/repositories/listenermanager.h \
    Sources/repositories/albummanager.h \
    Sources/repositories/playlistmanager.h \
    Sources/repositories/songmanager.h \
    Sources/repositories/datamanager.h \
    Sources/utils/filehelper.h \
    Sources/entities/account.h \
    Sources/entities/artist.h \
    Sources/entities/listener.h \
    Sources/entities/album.h \
    Sources/entities/playlist.h \
    Sources/entities/song.h

FORMS += \
    GUI/editaccountwindow.ui \
    GUI/editsongdialog.ui \
    GUI/playercontrol.ui \
    GUI/loginwindow.ui \
    GUI/registerwindow.ui \
    GUI/artistdashboard.ui \
    GUI/listenerdashboard.ui