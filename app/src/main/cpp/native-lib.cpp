#include <jni.h>
#include "GCloudVoice.h"
#include "android/log.h"
#include "native-lib.h"

using namespace gcloud_voice;
extern "C"
{

#define TAG "myDemo-jni" // 这个是自定义的LOG的标识   
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型   
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型   
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型   
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型   
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

GCVCallBack *myGCVCallBack = new GCVCallBack();
IGCloudVoiceEngine *gCloudVoiceEngine = gcloud_voice::GetVoiceEngine();

jint
Java_com_noteam_werewolves_MainActivity_initGC(
        JNIEnv *env,
        jobject,
        jstring openID) {

    IGCloudVoiceEngine *gCloudVoiceEngine = gcloud_voice::GetVoiceEngine();
    gCloudVoiceEngine->SetAppInfo("1777527173", "bc68ed52b7d28ea39f68468fba4d4651",
                                  (char *) env->GetStringUTFChars(openID, false));


//    LOGE("########## gCloudVoiceEngine = %d", (int)gCloudVoiceEngine);

    GCloudVoiceErrno code = gCloudVoiceEngine->Init();
    gCloudVoiceEngine->SetMode(gcloud_voice::IGCloudVoiceEngine::RealTime);
    gCloudVoiceEngine->SetNotify(myGCVCallBack);

    return code;
}


jint
Java_com_noteam_werewolves_MainActivity_joinTeamRoom(
        JNIEnv *env,
        jobject,
        jstring roomName) {
    GCloudVoiceErrno code = gCloudVoiceEngine->JoinTeamRoom(
            (char *) env->GetStringUTFChars(roomName, false), 10000);
    LOGE("########## JoinTeamRoom = %d", code);
//    LOGE("########## gcloud_voice::GetVoiceEngine() = %d", gcloud_voice::GetVoiceEngine());
    return code;

}

jint
Java_com_noteam_werewolves_MainActivity_openMic(
        JNIEnv *env,
        jobject /* this */) {
//    gCloudVoiceEngine->SetAppInfo("1777527173",
//                                  "bc68ed52b7d28ea39f68468fba4d4651",
//                                  "E81DCA1782C5CE8B0722A366D7ECB41F");
//    gCloudVoiceEngine->Init();
//    gCloudVoiceEngine->SetMode(gcloud_voice::IGCloudVoiceEngine::RealTime);
//    gCloudVoiceEngine->SetNotify(myCallBack);
//    gCloudVoiceEngine->JoinTeamRoom("cz_test2", 30000);
//    GCloudVoiceErrno code = gCloudVoiceEngine->Poll();
    GCloudVoiceErrno errno = gcloud_voice::GetVoiceEngine()->OpenMic();
    LOGE("########## OpenMic = %d", errno);
    return errno;
}

jint
Java_com_noteam_werewolves_MainActivity_openSpeaker(
        JNIEnv *env,
        jobject /* this */) {

    GCloudVoiceErrno errno = gcloud_voice::GetVoiceEngine()->OpenSpeaker();
    LOGE("########## i = %d", errno);
    return errno;
}

jint
Java_com_noteam_werewolves_MainActivity_poll(
        JNIEnv *env,
        jobject /* this */) {
//    myCallBack = new GCVCallBack();
//    gCloudVoiceEngine->SetAppInfo("1777527173",
//                                  "bc68ed52b7d28ea39f68468fba4d4651",
//                                  "E81DCA1782C5CE8B0722A366D7ECB41F");
//    gCloudVoiceEngine->Init();
//    gCloudVoiceEngine->SetMode(gcloud_voice::IGCloudVoiceEngine::RealTime);
//    gCloudVoiceEngine->SetNotify(myCallBack);
//    gcloud_voice::GetVoiceEngine()->JoinTeamRoom("cz_test2", 30000);
    GCloudVoiceErrno errno = gcloud_voice::GetVoiceEngine()->Poll();
    LOGD("########## Poll = %d", errno);
    return errno;
}

jint
Java_com_noteam_werewolves_MainActivity_closeSpeaker(
        JNIEnv *env,
        jobject /* this */) {
    return gcloud_voice::GetVoiceEngine()->CloseSpeaker();


}

jint
Java_com_noteam_werewolves_MainActivity_closeMic(
        JNIEnv *env,
        jobject /* this */) {

    return gcloud_voice::GetVoiceEngine()->CloseMic();

}

jint
Java_com_noteam_werewolves_MainActivity_quitRoom(
        JNIEnv *env,
        jobject,
        jstring roomName) {

    return gcloud_voice::GetVoiceEngine()->QuitRoom((char *) env->GetStringUTFChars(roomName, false), 10000);

}

}
