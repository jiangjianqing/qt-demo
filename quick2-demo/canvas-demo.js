.pragma library

/**
变换

Canvas中的“变形”，主要指的是坐标系的变换，而不是路径的变换。
这与 QML 元素变换非常相似，都可以实现坐标系统的scale（缩放）、rotate（旋转）和translate（平移）；
不同的是，变换的原点是画布原点。
例如，如果以一个路径的中心点为定点进行缩放，那么，你需要现将画布原点移动到路径中心点。
我们也可以使用变换函数实现复杂的变换。理解“变换是针对坐标系的”这一点非常重要，有时候可以避免很多意外的结果。

  **/

/**
像素缓存
使用canvas，你可以将canvas内容的像素数据读取出来，并且能够针对这些数据做一些操作。

使用createImageData(sw, sh)或getImageData(sx, sy, sw, sh)函数可以读取图像数据。
这两个函数都会返回一个ImageData对象，该对象具有width、height和data等变量。
data包含一个以 RGBA 格式存储的像素一维数组，其每一个分量值的范围都是 [0, 255]。
如果要设置画布上面的像素，可以使用putImageData(imagedata, dx, dy)函数。

另外一个获取画布内容的方法是，将数据保存到一个图片。这可以通过Canvas的函数save(path)或toDataURL(mimeType)实现，后者会返回一个图像的 URL，可以供Image元素加载图像。

  **/

//2017.09.12 重要： 经测试，无法支持prototype 和 class关键字，也就是说，没有面向对象的支持

function draw (ctx,width,height) {
    ctx.fillRect(0, 0, width, height);
    for (var i = 0; i < 3; i++) {
        for (var j = 0; j < 3; j++) {
            ctx.save();
            ctx.strokeStyle = "#9CFF00";
            ctx.translate(50 + j * 100, 50 + i * 100);
            drawSpirograph(ctx, 20 * (j + 2) / (j + 1), -8 * (i + 3) / (i + 1), 10);
            ctx.restore();
        }
    }
}

function drawSpirograph (ctx, R, r, O) {
    var x1 = R - O;
    var y1 = 0;
    var i  = 1;
    ctx.beginPath();
    ctx.moveTo(x1, y1);
    do {
        if (i > 20000) break;
        var x2 = (R + r) * Math.cos(i * Math.PI / 72) - (r + O) * Math.cos(((R + r) / r) * (i * Math.PI / 72))
        var y2 = (R + r) * Math.sin(i * Math.PI / 72) - (r + O) * Math.sin(((R + r) / r) * (i * Math.PI / 72))
        ctx.lineTo(x2, y2);
        x1 = x2;
        y1 = y2;
        i++;
    } while (x2 != R-O && y2 != 0 );
    ctx.stroke();
}
