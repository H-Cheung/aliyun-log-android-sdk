/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <libs/include/log_producer_client.h>

/* Header for class com_aliyun_sls_android_producer_LogProducerClient */

#ifndef _Included_com_aliyun_sls_android_producer_LogProducerClient
#define _Included_com_aliyun_sls_android_producer_LogProducerClient
#ifdef __cplusplus
extern "C" {
#endif

jobject g_obj;
JavaVM *g_VM;

void on_log_send_done(const char *config_name, log_producer_result result, size_t log_bytes,
                      size_t compressed_bytes, const char *req_id, const char *message) {
    JNIEnv *env = NULL;
    if ((*g_VM)->AttachCurrentThread(g_VM, &env, NULL) != JNI_OK) {
        return;
    }
    //通过全局变量g_obj 获取到要回调的类
    jclass java_class = (*env)->GetObjectClass(env, g_obj);

    if (java_class == 0) {
        (*g_VM)->DetachCurrentThread(g_VM);
        return;
    }
    //获取要回调的方法ID
    jmethodID java_callback_id = (*env)->GetMethodID(env, java_class,
                                                     "onCall",
                                                     "(ILjava/lang/String;Ljava/lang/String;II)V");
    if (java_callback_id == NULL) {
        return;
    }
    jstring req_id_jstr_buf = (*env)->NewStringUTF(env, req_id);
    jstring message_jstr_buf = (*env)->NewStringUTF(env, message);
    //执行回调
    (*env)->CallVoidMethod(env, g_obj, java_callback_id, result, req_id_jstr_buf, message_jstr_buf,
                           log_bytes, compressed_bytes);
    //释放当前线程
    (*g_VM)->DetachCurrentThread(g_VM);
    env = NULL;
}

/*
 * Class:     com_aliyun_sls_android_producer_LogProducerClient
 * Method:    create_log_producer
 * Signature: (Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jlong JNICALL
Java_com_aliyun_sls_android_producer_LogProducerClient_create_1log_1producer
        (JNIEnv *env, jclass obj, jlong config, jobject callback) {
    if (callback == NULL) {
        return (jlong) create_log_producer((log_producer_config *) config, NULL, NULL);
    }
    (*env)->GetJavaVM(env, &g_VM);
    g_obj = (*env)->NewGlobalRef(env, callback);
    return (jlong) create_log_producer((log_producer_config *) config, on_log_send_done, NULL);
}

/*
 * Class:     com_aliyun_sls_android_producer_LogProducerClient
 * Method:    get_log_producer_client
 * Signature: (Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jlong JNICALL
Java_com_aliyun_sls_android_producer_LogProducerClient_get_1log_1producer_1client
        (JNIEnv *env, jclass obj, jlong producer) {
    return (jlong) get_log_producer_client((log_producer *) producer, NULL);
}

/*
 * Class:     com_aliyun_sls_android_producer_LogProducerClient
 * Method:    log_producer_client_add_log_with_len
 * Signature: (Ljava/lang/Object;I[Ljava/lang/String;[I[Ljava/lang/String;[I)V
 */
JNIEXPORT jint JNICALL
Java_com_aliyun_sls_android_producer_LogProducerClient_log_1producer_1client_1add_1log_1with_1len
        (JNIEnv *env, jclass obj, jlong config, jlong log_time, jint pair_count, jobjectArray keys,
         jobjectArray values, jint flush) {
    int i;
    jsize len_keys = (*env)->GetArrayLength(env, keys);
    jstring jstr_keys[len_keys];
    char **c_keys = (char **) malloc(len_keys * sizeof(char *));
    int32_t *c_key_lens = (int32_t *) malloc(len_keys * sizeof(int32_t));
    for (i = 0; i < len_keys; i++) {
        jstr_keys[i] = (*env)->GetObjectArrayElement(env, keys, i);
        c_keys[i] = (char *) (*env)->GetStringUTFChars(env, jstr_keys[i], 0);
        c_key_lens[i] = strlen(c_keys[i]);
    }
    jsize len_values = (*env)->GetArrayLength(env, values);
    jstring jstr_values[len_values];
    char **c_values = (char **) malloc(len_values * sizeof(char *));
    int32_t *c_value_lens = (int32_t *) malloc(len_values * sizeof(int32_t));
    for (i = 0; i < len_values; i++) {
        jstr_values[i] = (*env)->GetObjectArrayElement(env, values, i);
        c_values[i] = (char *) (*env)->GetStringUTFChars(env, jstr_values[i], 0);
        c_value_lens[i] = strlen(c_values[i]);
    }

    int res = log_producer_client_add_log_with_len_time_int32((log_producer_client *) config, log_time, pair_count,
                                                         c_keys, c_key_lens, c_values, c_value_lens,
                                                         flush);

    for (i = 0; i < len_keys; i++) {
        (*env)->ReleaseStringUTFChars(env, jstr_keys[i], c_keys[i]);
    }
    for (i = 0; i < len_values; i++) {
        (*env)->ReleaseStringUTFChars(env, jstr_values[i], c_values[i]);
    }
    free(c_keys);
    free(c_key_lens);
    free(c_values);
    free(c_value_lens);
    return res;
}

/*
 * Class:     com_aliyun_sls_android_producer_LogProducerClient
 * Method:    destroy_log_producer
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL
Java_com_aliyun_sls_android_producer_LogProducerClient_destroy_1log_1producer
        (JNIEnv *env, jclass obj, jlong producer) {
    destroy_log_producer((log_producer *) producer);
}

/*
 * Class: com_aliyun_sls_android_producer_LogProducerClient
 * Method: log_producer_client_add_log_with_len_time_int32
 */
JNIEXPORT jint JNICALL
Java_com_aliyun_sls_android_producer_LogProducerClient_log_1producer_1client_1add_1log_1with_1len_1time_1int32(
        JNIEnv *env, jclass clazz, jlong config, jlong log_time, jint pair_count, jobjectArray keys,
        jobjectArray values) {
    jsize len_keys = (*env)->GetArrayLength(env, keys);
    jobjectArray key_array[len_keys];
    char **c_keys = (char **) malloc(len_keys * sizeof(char *));
    int32_t *c_key_lens = (int32_t *) malloc(len_keys * sizeof(int32_t));
    int i;
    for (i = 0; i < len_keys; i++) {
        key_array[i] = (*env)->GetObjectArrayElement(env, keys, i);
        jsize cols = (*env)->GetArrayLength(env, key_array[i]);
        c_keys[i] = (char *) (*env)->GetByteArrayElements(env, key_array[i], 0);
        c_key_lens[i] = cols;
    }

    jsize len_values = (*env)->GetArrayLength(env, values);
    jobjectArray value_array[len_values];
    char **c_values = (char **) malloc(len_values * sizeof(char *));
    int32_t *c_value_lens = (int32_t *) malloc(len_values * sizeof(int32_t));
    for (i = 0; i < len_values; i++) {
        value_array[i] = (*env)->GetObjectArrayElement(env, values, i);
        jsize cols = (*env)->GetArrayLength(env, value_array[i]);
        c_values[i] = (char *) (*env)->GetByteArrayElements(env, value_array[i], 0);
        c_value_lens[i] = cols;
    }

    int res = log_producer_client_add_log_with_len_time_int32((log_producer_client *) config, log_time, pair_count,
                                                              c_keys, c_key_lens, c_values, c_value_lens,
                                                              0);

    for (i = 0; i < len_keys; i++) {
        (*env)->ReleaseByteArrayElements(env, key_array[i], (jbyte *)c_keys[i], JNI_COMMIT);
    }
    for (i = 0; i < len_values; i++) {
        (*env)->ReleaseByteArrayElements(env, value_array[i], (jbyte *)c_values[i], JNI_COMMIT);
    }
    free(c_keys);
    free(c_key_lens);
    free(c_values);
    free(c_value_lens);
    return res;
}

#ifdef __cplusplus
}
#endif
#endif
