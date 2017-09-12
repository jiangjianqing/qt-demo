import QtQuick 2.7
import "canvas-demo.js" as CanvasDemo  //特别重要:引入js时第一个字母必须大写!!!!!!!!!!!

PageCanvasForm {
    //自定义画布
    Canvas {
        id: canvas;
        anchors.fill: parent;

        //组合的意思是，将你绘制的图形与已存在的像素做一些融合操作。canvas支持几种组合方式，使用globalCompositeOperation可以设置组合的模式。
        // TODO: does not work yet
        //ctx.globalCompositeOperation = root.operation[i]
        property var operation : [
                'source-over', 'source-in', 'source-over',
                'source-atop', 'destination-over', 'destination-in',
                'destination-out', 'destination-atop', 'lighter',
                'copy', 'xor', 'qt-clear', 'qt-destination',
                'qt-multiply', 'qt-screen', 'qt-overlay', 'qt-darken',
                'qt-lighten', 'qt-color-dodge', 'qt-color-burn',
                'qt-hard-light', 'qt-soft-light', 'qt-difference',
                'qt-exclusion'
                ]

        //再次函数中绘制图形
        onPaint: {
            var ctx = getContext("2d");
            CanvasDemo.draw(ctx,width,height);
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                var url = canvas.toDataURL('image/png')
                print('image url=', url)
                image.source = url
            }
        }

        Image {
            id: image
            x: 130; y: 10
            width: 100; height: 100
        }

        Timer {
            interval: 1000
            running: false
            triggeredOnStart: true
            repeat: true
            onTriggered: canvas.requestPaint()
        }


    }
}
