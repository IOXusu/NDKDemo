#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_xusu_ndkdemo_Hello_stringFromJNI(
        JNIEnv *env,
        jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/*
 * Class:     com_xusu_ndkdemo_Hello
 * Method:    callStaticMethod
 * Signature: (I)V
 *  调用java类的static静态相关
 */

extern "C" JNIEXPORT void JNICALL
Java_com_xusu_ndkdemo_Hello_callStaticMethod(JNIEnv *env, jclass clazz, jint i) {
    jclass cls_hello = env->FindClass("com/xusu/ndkdemo/Hello");
    if (cls_hello == NULL) { return; }
    jmethodID mtd_static_method = env->GetStaticMethodID(cls_hello, "staticMethod",
                                                         "(Ljava/lang/String;)V");
    if (mtd_static_method == NULL) { return; }
    jstring data = env->NewStringUTF("c callStaticMethod 哈哈哈哈");

    //修改变量
    jfieldID fld_name = env->GetStaticFieldID(cls_hello, "name", "Ljava/lang/String;");
    if (fld_name == NULL) { return; }
    jstring name = env->NewStringUTF("cName");
    env->SetStaticObjectField(cls_hello, fld_name, name);

    if (data == NULL) { return; }
    env->CallStaticVoidMethod(cls_hello, mtd_static_method, data);

    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(data);
    env->DeleteLocalRef(name);
}

/*
 * Class:     com_xusu_ndkdemo_Hello
 * Method:    method
 * Signature: (I)V
 *  调用java类的实例相关
 */

extern "C" JNIEXPORT void JNICALL
Java_com_xusu_ndkdemo_Hello_callInstanceMethod(JNIEnv *env, jobject thiz, jint i) {
    jclass cls_hello = env->FindClass("com/xusu/ndkdemo/Hello");
    if (cls_hello == NULL) { return; }

    jmethodID mtd_method = env->GetMethodID(cls_hello, "method", "(Ljava/lang/String;)V");
    if (mtd_method == NULL) { return; }

    jmethodID mtd_construct = env->GetMethodID(cls_hello, "<init>", "()V");
    if (mtd_construct == NULL) { return; }

    jfieldID fld_adress = env->GetFieldID(cls_hello, "address", "Ljava/lang/String;");
    if (fld_adress == NULL) { return; }

    jobject hello = env->NewObject(cls_hello, mtd_construct, NULL);
    if (hello == NULL) { return; }

    jstring address = env->NewStringUTF("shanghai");
    env->SetObjectField(hello, fld_adress, address);

    jstring data = env->NewStringUTF("c callInstanceMethod 哈哈哈哈");
    env->CallVoidMethod(hello, mtd_method, data);



    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(hello);
    env->DeleteLocalRef(data);
    env->DeleteLocalRef(address);
}