#define MINIAUDIO_IMPLEMENTATION

#include <iostream>
#include "DFT.h"
#include "./library/miniaudio.h"

#include <stdio.h>

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);
    float* pOutputF32 = (float*)pOutput;


//    for (ma_uint32 i = 0; i < frameCount; i++) {
//        std::cout << "data_callback pOutput " << pOutputF32[i] << std::endl;
//    }

    (void)pInput;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    //Hsinpa::DFT dft = Hsinpa::DFT();

    const char* sample_mp3_path = "../assets/file_example_MP3_1MG.mp3";
    ma_device_config deviceConfig;
    ma_device device;
    ma_decoder decoder;
    ma_result result;

    ma_context context;
    ma_device_info* pPlaybackDeviceInfos;
    ma_uint32 playbackDeviceCount;
    ma_device_info* pCaptureDeviceInfos;
    ma_uint32 captureDeviceCount;
    ma_uint32 iDevice;

    result = ma_decoder_init_file(sample_mp3_path, NULL, &decoder);
    if (result != MA_SUCCESS) {
        return -1;   // An error occurred.
    }

    if (ma_context_init(NULL, 0, NULL, &context) != MA_SUCCESS) {
        printf("Failed to initialize context.\n");
        return -2;
    }
    result = ma_context_get_devices(&context, &pPlaybackDeviceInfos, &playbackDeviceCount, &pCaptureDeviceInfos, &captureDeviceCount);
    if (result != MA_SUCCESS) {
        printf("Failed to retrieve device information.\n");
        return -3;
    }

    printf("Playback Devices\n");
    for (iDevice = 0; iDevice < playbackDeviceCount; ++iDevice) {
        printf("    %u: %s\n", iDevice, pPlaybackDeviceInfos[iDevice].name);
    }

    printf("\n");

    printf("Capture Devices\n");
    for (iDevice = 0; iDevice < captureDeviceCount; ++iDevice) {
        printf("    %u: %s\n", iDevice, pCaptureDeviceInfos[iDevice].name);
    }


    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate        = decoder.outputSampleRate;
    deviceConfig.dataCallback      = data_callback;
    deviceConfig.pUserData         = &decoder;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return -3;
    }
//
//
//    if (ma_device_start(&device) != MA_SUCCESS) {
//        printf("Failed to start playback device.\n");
//        ma_device_uninit(&device);
//        ma_decoder_uninit(&decoder);
//        return -4;
//    }
//



//    printf("Press Enter to quit...");
//    getchar();
    int frameCount = 512;
    float pOutputF32[frameCount];
    ma_uint64 framesRead;
    
    ma_result seek_to_pcm_result = ma_decoder_seek_to_pcm_frame(&decoder, 44100*2);
    ma_result read_pcm_result = ma_decoder_read_pcm_frames(&decoder, pOutputF32, frameCount, &framesRead);

    for (ma_uint32 i = 0; i < frameCount; i++) {
        std::cout << "data_callback pOutput " << pOutputF32[i] << std::endl;
    }

    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
    return 0;
}
