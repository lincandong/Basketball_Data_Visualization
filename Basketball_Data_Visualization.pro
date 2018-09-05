######################################################################
# Automatically generated by qmake (3.1) Sun Jul 22 23:01:38 2018
######################################################################
QT += widgets
QT += charts
QT += core gui
TEMPLATE = app
TARGET = Basketball_Data_Visualization
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += commands/allcommand.h \
           common/common.h \
           common/dataType.h \
           common/receiver.h \
           common/sender.h \
           model/model.h \
           view/myLabel.h \
           view/pageData.h \
           view/pagePlayer.h \
           view/pageRank.h \
           view/pageStart.h \
           view/pageTeam.h \
           view/view.h \
           viewmodel/viewmodel.h \
           commands/base/command.h \
           commands/base/parameters.h \
           commands/inherit/playerDataCommand.h \
           commands/inherit/playerRankCommand.h \
           commands/inherit/teamDataCommand.h \
           commands/inherit/teamRankCommand.h \
           common/rapidjson/allocators.h \
           common/rapidjson/cursorstreamwrapper.h \
           common/rapidjson/document.h \
           common/rapidjson/encodedstream.h \
           common/rapidjson/encodings.h \
           common/rapidjson/filereadstream.h \
           common/rapidjson/filewritestream.h \
           common/rapidjson/fwd.h \
           common/rapidjson/istreamwrapper.h \
           common/rapidjson/memorybuffer.h \
           common/rapidjson/memorystream.h \
           common/rapidjson/ostreamwrapper.h \
           common/rapidjson/pointer.h \
           common/rapidjson/prettywriter.h \
           common/rapidjson/rapidjson.h \
           common/rapidjson/reader.h \
           common/rapidjson/schema.h \
           common/rapidjson/stream.h \
           common/rapidjson/stringbuffer.h \
           common/rapidjson/writer.h \
           view/receiver/viewCommandReceiver.h \
           view/receiver/viewPropertyReceiver.h \
           viewmodel/receiver/receiverFromModel.h \
           viewmodel/receiver/receiverFromView.h \
           common/rapidjson/error/en.h \
           common/rapidjson/error/error.h \
           common/rapidjson/internal/biginteger.h \
           common/rapidjson/internal/diyfp.h \
           common/rapidjson/internal/dtoa.h \
           common/rapidjson/internal/ieee754.h \
           common/rapidjson/internal/itoa.h \
           common/rapidjson/internal/meta.h \
           common/rapidjson/internal/pow10.h \
           common/rapidjson/internal/regex.h \
           common/rapidjson/internal/stack.h \
           common/rapidjson/internal/strfunc.h \
           common/rapidjson/internal/strtod.h \
           common/rapidjson/internal/swap.h \
           common/rapidjson/msinttypes/inttypes.h \
           common/rapidjson/msinttypes/stdint.h \
           common/rapidjson/filereadstream.h \
           common/rapidjson/msinttypes/stdint.h \
           common/rapidjson/msinttypes/inttypes.h \
           common/rapidjson/document.h \
    view/playertablemodel.h
FORMS += view/pageData.ui \
         view/pagePlayer.ui \
         view/pageRank.ui \
         view/pageStart.ui \
         view/pageTeam.ui \
         view/view.ui
SOURCES += common/sender.cpp \
           model/model.cpp \
           view/myLabel.cpp \
           view/pageData.cpp \
           view/pagePlayer.cpp \
           view/pageRank.cpp \
           view/pageStart.cpp \
           view/pageTeam.cpp \
           view/view.cpp \
           viewmodel/viewmodel.cpp \
           commands/base/command.cpp \
           commands/inherit/playerDataCommand.cpp \
           commands/inherit/playerRankCommand.cpp \
           commands/inherit/teamDataCommand.cpp \
           commands/inherit/teamRankCommand.cpp \
           view/receiver/viewCommandReceiver.cpp \
           view/receiver/viewPropertyReceiver.cpp \
           viewmodel/receiver/receiverFromModel.cpp \
           viewmodel/receiver/receiverFromView.cpp \
    app/main.cpp \
    view/playertablemodel.cpp
RESOURCES += resources/resources.qrc