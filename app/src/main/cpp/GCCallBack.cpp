#include "GCCallBack.h"
#include <jni.h>
#include <string>
#include <android/log.h>
#define TAG "myDemo-jni" // 这个是自定义的LOG的标识   
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型   
using namespace gcloud_voice;



    void GCVCallBack::OnJoinRoom(GCloudVoiceCompleteCode code, const char *roomName, int memberID) {
        LOGE("########## OnJoinRoom memberID= %d", memberID);
//        GCloudVoiceErrno errno = gcloud_voice::GetVoiceEngine()->OpenMic();
//        LOGE("########## OnJoinRoom = %d", errno);
//        gcloud_voice::GetVoiceEngine()->OpenSpeaker();
    }

    /**
     * Callback when dropped from the room
     *
     * @param code : a GCloudVoiceCompleteCode code . You should check this first.
     * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
     * @param memberID : if success, return the memberID
     */
    void GCVCallBack::OnStatusUpdate(GCloudVoiceCompleteCode status, const char *roomName, int memberID) {
        LOGE("########## OnStatusUpdate = %s", "OnStatusUpdate");
    }

    /**
     * Callback when QuitRoom successful or failed.
     *
     * @param code : a GCloudVoiceCompleteCode code . You should check this first.
     * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
     */
    void GCVCallBack:: OnQuitRoom(GCloudVoiceCompleteCode code, const char *roomName) {
        LOGE("########## OnQuitRoom = %s", "OnQuitRoom");
    }

    /**
     * Callback when someone saied or silence in the same room.
     *
     * @param count: count of members who's status has changed.
     * @param members: a int array composed of [memberid_0, status,memberid_1, status ... memberid_2*count, status]
     * here, status could be 0, 1, 2. 0 meets silence and 1/2 means saying
     */
    void GCVCallBack::OnMemberVoice(const unsigned int *members, int count) {
        LOGE("########## OnMemberVoice = %s", "OnMemberVoice");
    }

    // Voice Message Callback
    /**
     * Callback when upload voice file successful or failed.
     *
     * @param code: a GCloudVoiceCompleteCode code . You should check this first.
     * @param filePath: file to upload
     * @param fileID: if success ,get back the id for the file.
     */
    void GCVCallBack::OnUploadFile(GCloudVoiceCompleteCode code, const char *filePath, const char *fileID) {
        LOGE("########## OnUploadFile = %s", "OnUploadFile");
    }

    /**
     * Callback when download voice file successful or failed.
     *
     * @param code: a GCloudVoiceCompleteCode code . You should check this first.
     * @param filePath: file to download to .
     * @param fileID: if success ,get back the id for the file.
     */
    void GCVCallBack::OnDownloadFile(GCloudVoiceCompleteCode code, const char *filePath, const char *fileID) { }

    /**
     * Callback when finish a voice file play end.
     *
     * @param code: a GCloudVoiceCompleteCode code . You should check this first.
     * @param filePath: file had been plaied.
     */
    void GCVCallBack::OnPlayRecordedFile(GCloudVoiceCompleteCode code, const char *filePath) { }

    /**
     * Callback when query message key successful or failed.
     *
     * @param code: a GCloudVoiceCompleteCode code . You should check this first.
     */
    void GCVCallBack::OnApplyMessageKey(GCloudVoiceCompleteCode code) { }

    // Translate
    /**
     * Callback when translate voice to text successful or failed.
     *
     * @param code: a GCloudVoiceCompleteCode code . You should check this first.
     * @param fileID : file to translate
     * @param result : the destination text of the destination language.
     */
    void GCVCallBack::OnSpeechToText(GCloudVoiceCompleteCode code, const char *fileID, const char *result) { }

    /**
     * Callback when client is using microphone recording audio
     *
     * @param pAudioData : audio data pointer 
     * @param nDataLength : audio data length
     * @param result : void
     */
    void GCVCallBack::OnRecording(const unsigned char *pAudioData, unsigned int nDataLength) {
        LOGE("########## OnRecording = %s", "OnRecording");
        
    }
