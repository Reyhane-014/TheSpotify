QT       += core widgets

TARGET = TheSpotify
TEMPLATE = app

SOURCES += \
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
    Sources/entities/account.cpp \
    Sources/entities/artist.cpp \
    Sources/entities/listener.cpp \
    Sources/entities/album.cpp \
    Sources/entities/playlist.cpp \
    Sources/entities/song.cpp

HEADERS += \
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
    Sources/entities/account.h \
    Sources/entities/artist.h \
    Sources/entities/listener.h \
    Sources/entities/album.h \
    Sources/entities/playlist.h \
    Sources/entities/song.h

FORMS += \
    GUI/loginwindow.ui \
    GUI/registerwindow.ui \
    GUI/artistdashboard.ui \
    GUI/listenerdashboard.ui