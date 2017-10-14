2017.10.14:
环境:linux manjaro ,gcc版本7.2.0,
使用cmake-gui生成的build执行make命令，出现错误：.../6.2.0/cstdlib:75:25: fatal error: stdlib.h: No such file or directory
 #include_next <stdlib.h>
原因：可能是gcc版本过高
解决办法：
	Try by disabling pre-compiled headers, either from cmake-gui or using the command line parameter：
	-DENABLE_PRECOMPILED_HEADERS=OFF



##注意事项：
1、ImagePlay当前只支持opencv3.1
2、cmake版本存在一定的不兼容情况：
    在编译opencv3.1时，用cmake-3.4.3可以通过所有编译，用cmake-3.9.3编译时opencv_bioinspired310时出现异常。

##编译opencv的步骤(windows)
1、下载opencv-3.1.0,opencv_contrib-3.1.0
2、用cmake-gui生成vs2015项目
    a)source code 目录指定 ${opencv-3.1.0}/opencv/sources
    b)build the binaries：指定build目录 例如 C:/opencv31build/x64
    c)执行Configure
    d)设置OPENCV_EXTRA_MODULES_PATH,指向${opencv_contrib-3.1.0}/modules
    e)执行Generate,在b)指定的${build}目录下获得vs项目
    f)用vs打开${build}下的项目解决方案，使用生成->批量生成命令，将Install包的Debug和Release全部生成
    g)在${build}/install下，就是编译后的opencv文件
    h)结束

##cmake使用

查看支持的编译器
···shell
cmake -G    #查看所有支持的编译器
cmake .. -G "Visual Studio 14 2015 Win64"   #假设当前目录为build，上一级目录包含CMakeLists.txt,在build目录下执行该命令会生成vc 14的64位项目
···