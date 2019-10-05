
编译：

    cd app/src/main/java
    javah -encoding UTF-8 -d ../jni com.lqm.ndkjnistudy.Hello       //-d:生成目录  .. ：当前文件的上层文件夹


    cd app/build/intermediates/javac/debug/classes
    javap -s com.lqm.ndkjnistudy.Hello  //查看方法签名

加载so:
    System.loadLibrary("native-lib");

    ndk{
        moduleName "JniDemo" // 设置生成的文件名
        cFlags "-DANDROID_NDK -D_RELEASE" //这个对应的是生成模式
        ldLibs "m", "log", "jnigraphics" //这个对应 LOCAL_LDLIBS 但是需要去掉前面的 “l”
        abiFilters "all" //这个是对应的 APP_ABI
        stl "stlport_shared" //这个对应的是 APP_STL
    }

ABI: 应用程序二进制接口（Application Binary Interface） 定义了二进制文件（.os文件）
     在Android系统上，每一个CPU架构对应一个ABI：armeabi	armeabi-v7a	arm64-v8a	mips	mips64	x86	x86_64 (常见：armeabi-v7a)


打印Log信息：
    如果你用的是正式版gradle,在ndk标签中加入 ：ldLibs "log"
    如果你用的是实验版gradle,在ndk标签中加入：ldLibs.add("log")
    如果你使用CMakeLists，在target_link_libraries标签中加入log
    如果你使用的是MK文件，加入如下语句：LOCAL_LDLIBS := -llog

查看方法签名：
    G:\myProject\NdkJniStudy\app\build\intermediates\classes\debug>javap -s com.lqm.ndkjnistudy.Hello


adb logcat :查看log信息




























