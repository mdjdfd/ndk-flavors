#include<jni.h>
#include<string.h>


/**
function naming rule:
Java_package name(dot replaced with underscore)_calling activity name_function name
**/

JNIEXPORT jstring JNICALL Java_com_opensource_nativeinterfacing_MainActivity_getJNIString(JNIEnv* env, jobject obj){
    return (*env) -> NewStringUTF(env, "Sample String");
}

JNIEXPORT jint JNICALL Java_com_opensource_nativeinterfacing_MainActivity_doJNIAddition(JNIEnv* env, jobject obj, jint num1, jint num2){
    return num1 + num2;
}

JNIEXPORT jboolean JNICALL Java_com_opensource_nativeinterfacing_MainActivity_doJNICompare(JNIEnv* env, jobject obj, jint num1, jint num2){
    return (num1 > num2) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jobject JNICALL Java_com_opensource_nativeinterfacing_MainActivity_createJNIUser(JNIEnv* env, jobject obj, jint age){
    jclass userClass = (*env) -> FindClass(env,"com/opensource/nativeinterfacing/User");
    //jmethodID midConstructor = (*env) -> GetMethodID(env, userClass, "<init>", "(I)V");  // passing by constructor
    jmethodID midConstructor = (*env) -> GetMethodID(env, userClass, "setmAge", "(I)V");   // passing by setter
    jobject userObject = (*env) -> NewObject(env, userClass, midConstructor, age);
    return userObject;
}

JNIEXPORT jint JNICALL Java_com_opensource_nativeinterfacing_MainActivity_getJNIUser(JNIEnv* env, jobject obj, jobject user){
    jclass userClass = (*env) -> GetObjectClass(env, user);
    jmethodID ageID = (*env) -> GetMethodID(env, userClass, "getmAge", "()I");
    int age =  (*env)-> CallIntMethod(env, user, ageID);
    return age;
}