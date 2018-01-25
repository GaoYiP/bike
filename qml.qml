/*import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
*/
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtMultimedia 5.5

/*
ApplicationWindow {
    id:mainWin
    visible: true
    width: 640
    height: 480
*/
    Item {
        anchors.fill: parent

        Camera {
            id: camera
            focus {
                focusMode: Camera.FocusContinuous
                focusPointMode: Camera.FocusPointCustom
                customFocusPoint: Qt.point(0.2, 0.2) // Focus relative to top-left corner
            }
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceAuto
            exposure {
                exposureCompensation: -1.0
                exposureMode: Camera.ExposurePortrait
            }
            flash.mode: Camera.FlashRedEyeReduction
            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview  // Show the preview in an Image
                }
            }

        }


        VideoOutput {
            id:videoOut
            source: camera
            //anchors.fill: parent
            autoOrientation:true;
            focus : visible // to receive focus and capture key events when visible
        }
        /*
        MouseArea {
                    //anchors.fill: parent;
                    onClicked: camera.imageCapture.capture();
        }
        */
        Image {
            id: photoPreview
        }
    }

/*
    Button {
        width: mainWin.width/20
        height: mainWin/20
        onClicked: {
            if(videoOut.rotation== 0) {
                videoOut.rotation = 90;
            } else if(videoOut.rotation == 90) {
                videoOut.rotation = 180;
            } else if(videoOut.rotation == 180) {
                videoOut.rotation = 270;
            } else {
                videoOut.rotation = 0
            }
        }
    }


}
 */
