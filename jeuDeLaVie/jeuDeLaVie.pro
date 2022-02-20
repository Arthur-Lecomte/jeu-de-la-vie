TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        affichageMatrice.cpp \
        automateCellulaire.cpp \
        main.cpp \
        regle.cpp \
        remplirMatrice.cpp \
        structCellule.cpp \
        voisin.cpp

HEADERS += \
    affichageMatrice.h \
    automateCellulaire.h \
    regle.h \
    remplirMatrice.h \
    structCellule.h \
    voisin.h
