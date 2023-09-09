/*
**
** Copyright 2015, Samsung Electronics Co. LTD
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/* #define LOG_NDEBUG 0 */
#define LOG_TAG "ExynosCamera3FrameFactory"
#include <cutils/log.h>

#include "ExynosCamera3FrameFactory.h"

namespace android {

ExynosCamera3FrameFactory::~ExynosCamera3FrameFactory()
{
    status_t ret = NO_ERROR;

    ret = destroy();
    if (ret != NO_ERROR)
        CLOGE("ERR(%s[%d]):destroy fail", __FUNCTION__, __LINE__);
}

status_t ExynosCamera3FrameFactory::precreate(void)
{
    CLOGE("ERR(%s[%d]):Must use the concreate class, don't use superclass", __FUNCTION__, __LINE__);
    return INVALID_OPERATION;
}

status_t ExynosCamera3FrameFactory::postcreate(void)
{
    CLOGE("ERR(%s[%d]):Must use the concreate class, don't use superclass", __FUNCTION__, __LINE__);
    return INVALID_OPERATION;
}

status_t ExynosCamera3FrameFactory::destroy(void)
{
    CLOGI("INFO(%s[%d])", __FUNCTION__, __LINE__);
    status_t ret = NO_ERROR;

    for (int i = 0; i < MAX_NUM_PIPES; i++) {
        if (m_pipes[i] != NULL) {
            ret = m_pipes[i]->destroy();
            if (ret != NO_ERROR) {
                CLOGE("ERR(%s[%d]):m_pipes[%d]->destroy() fail", __FUNCTION__, __LINE__, i);

                if (m_shot_ext != NULL) {
                    delete m_shot_ext;
                    m_shot_ext = NULL;
                }

                return ret;
            }

            SAFE_DELETE(m_pipes[i]);

            CLOGD("DEBUG(%s):Pipe(%d) destroyed", __FUNCTION__, i);
        }
    }

    if (m_shot_ext != NULL) {
        delete m_shot_ext;
        m_shot_ext = NULL;
    }

    ret = m_transitState(FRAME_FACTORY_STATE_NONE);

    return ret;
}

status_t ExynosCamera3FrameFactory::mapBuffers(void)
{
    CLOGE("ERR(%s[%d]):Must use the concreate class, don't use superclass", __FUNCTION__, __LINE__);
    return INVALID_OPERATION;
}

status_t ExynosCamera3FrameFactory::fastenAeStable(__unused int32_t numFrames, __unused ExynosCameraBuffer *buffers)
{
    CLOGE("ERR(%s[%d]):Must use the concreate class, don't use superclass", __FUNCTION__, __LINE__);
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::setStopFlag(void)
{
    CLOGE("ERR(%s[%d]):Must use the concreate class, don't use superclass", __FUNCTION__, __LINE__);
    return INVALID_OPERATION;
}

status_t ExynosCamera3FrameFactory::stopPipe(uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(pipeId)]->stopThread();
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):Pipe:%d stopThread fail, ret(%d)", __FUNCTION__, __LINE__, pipeId, ret);
        /* TODO: exception handling */
        return INVALID_OPERATION;
    }

    ret = m_pipes[INDEX(pipeId)]->stop();
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):Pipe:%d stop fail, ret(%d)", __FUNCTION__, __LINE__, pipeId, ret);
        /* TODO: exception handling */
        /* return INVALID_OPERATION; */
    }

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::startThread(uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    CLOGI("INFO(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);

    ret = m_pipes[INDEX(pipeId)]->startThread();
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):start thread fail, pipeId(%d), ret(%d)", __FUNCTION__, __LINE__, pipeId, ret);
        /* TODO: exception handling */
    }
    return ret;
}

status_t ExynosCamera3FrameFactory::stopThread(uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    CLOGI("INFO(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);

    if (m_pipes[INDEX(pipeId)] == NULL) {
        CLOGE("ERR(%s[%d]):m_pipes[INDEX(%d)] == NULL. so, fail", __FUNCTION__, __LINE__, pipeId);
        return INVALID_OPERATION;
    }

    ret = m_pipes[INDEX(pipeId)]->stopThread();
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):stop thread fail, pipeId(%d), ret(%d)", __FUNCTION__, __LINE__, pipeId, ret);
        /* TODO: exception handling */
    }
    return ret;
}

status_t ExynosCamera3FrameFactory::stopThreadAndWait(uint32_t pipeId, int sleep, int times)
{
    status_t ret = NO_ERROR;

    CLOGI("INFO(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);
    ret = m_pipes[INDEX(pipeId)]->stopThreadAndWait(sleep, times);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):pipe(%d) stopThreadAndWait fail, ret(%d)", __FUNCTION__, __LINE__, pipeId, ret);
        /* TODO: exception handling */
        ret = INVALID_OPERATION;
    }
    return ret;
}

bool ExynosCamera3FrameFactory::checkPipeThreadRunning(uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(pipeId)]->isThreadRunning();

    return ret;
}

status_t ExynosCamera3FrameFactory::setFrameManager(ExynosCameraFrameManager *manager)
{
    m_frameMgr = manager;
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getFrameManager(ExynosCameraFrameManager **manager)
{
    *manager = m_frameMgr;
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::setBufferManagerToPipe(ExynosCameraBufferManager **bufferManager, uint32_t pipeId)
{
    if (m_pipes[INDEX(pipeId)] == NULL) {
        CLOGE("ERR(%s[%d])m_pipes[INDEX(%d)] == NULL. pipeId(%d)", __FUNCTION__, __LINE__, INDEX(pipeId), pipeId);
        return INVALID_OPERATION;
    }

    return m_pipes[INDEX(pipeId)]->setBufferManager(bufferManager);
}

status_t ExynosCamera3FrameFactory::setOutputFrameQToPipe(frame_queue_t *outputQ, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->setOutputFrameQ(outputQ);
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getOutputFrameQToPipe(frame_queue_t **outputQ, uint32_t pipeId)
{
    CLOGV("DEBUG(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);
    m_pipes[INDEX(pipeId)]->getOutputFrameQ(outputQ);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::setFrameDoneQToPipe(frame_queue_t *frameDoneQ, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->setFrameDoneQ(frameDoneQ);
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getFrameDoneQToPipe(frame_queue_t **frameDoneQ, uint32_t pipeId)
{
    CLOGV("DEBUG(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);
    m_pipes[INDEX(pipeId)]->getFrameDoneQ(frameDoneQ);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getInputFrameQToPipe(frame_queue_t **inputFrameQ, uint32_t pipeId)
{
    CLOGV("DEBUG(%s[%d]):pipeId=%d", __FUNCTION__, __LINE__, pipeId);

    m_pipes[INDEX(pipeId)]->getInputFrameQ(inputFrameQ);

    if (inputFrameQ == NULL)
        CLOGE("ERR(%s[%d])inputFrameQ is NULL", __FUNCTION__, __LINE__);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::pushFrameToPipe(ExynosCameraFrame **newFrame, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->pushFrame(newFrame);
    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::setParam(struct v4l2_streamparm *streamParam, uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(pipeId)]->setParam(*streamParam);

    return ret;
}

status_t ExynosCamera3FrameFactory::setControl(int cid, int value, uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(pipeId)]->setControl(cid, value);

    return ret;
}

status_t ExynosCamera3FrameFactory::getControl(int cid, int *value, uint32_t pipeId)
{
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(pipeId)]->getControl(cid, value);

    return ret;
}

void ExynosCamera3FrameFactory::setRequest(int pipeId, bool enable)
{
    switch (pipeId) {
    case PIPE_FLITE:
    case PIPE_FLITE_REPROCESSING:
        m_requestFLITE = enable ? 1 : 0;
        break;
    case PIPE_VC1:
        m_requestVC1 = enable ? 1 : 0;
        break;
    case PIPE_VC2:
        m_requestVC2 = enable ? 1 : 0;
        break;
    case PIPE_VC3:
        m_requestVC3 = enable ? 1 : 0;
        break;
    case PIPE_3AC:
    case PIPE_3AC_REPROCESSING:
        m_request3AC = enable ? 1 : 0;
        break;
    case PIPE_3AP:
    case PIPE_3AP_REPROCESSING:
        m_request3AP = enable ? 1 : 0;
        break;
    case PIPE_ISPC:
    case PIPE_ISPC_REPROCESSING:
        m_requestISPC = enable ? 1 : 0;
        break;
    case PIPE_ISPP:
    case PIPE_ISPP_REPROCESSING:
        m_requestISPP = enable ? 1 : 0;
        break;
    case PIPE_MCSC0:
    case PIPE_MCSC0_REPROCESSING:
        m_requestMCSC0 = enable ? 1 : 0;
        break;
    case PIPE_MCSC1:
    case PIPE_MCSC1_REPROCESSING:
        m_requestMCSC1 = enable ? 1 : 0;
        break;
    case PIPE_MCSC2:
    case PIPE_MCSC2_REPROCESSING:
        m_requestMCSC2 = enable ? 1 : 0;
        break;
    case PIPE_MCSC3:
    case PIPE_MCSC3_REPROCESSING:
        m_requestMCSC3 = enable ? 1 : 0;
        break;
    case PIPE_MCSC4:
    case PIPE_MCSC4_REPROCESSING:
        m_requestMCSC4 = enable ? 1 : 0;
        break;
    case PIPE_HWFC_JPEG_SRC_REPROCESSING:
    case PIPE_HWFC_JPEG_DST_REPROCESSING:
        m_requestJPEG = enable ? 1 : 0;
        break;
    case PIPE_HWFC_THUMB_SRC_REPROCESSING:
    case PIPE_HWFC_THUMB_DST_REPROCESSING:
        m_requestThumbnail = enable ? 1 : 0;
        break;
    default:
        CLOGW("WRN(%s[%d]):Invalid pipeId(%d)", __FUNCTION__, __LINE__, pipeId);
        break;
    }
}

void ExynosCamera3FrameFactory::setRequestFLITE(bool enable)
{
#if 1
    m_requestFLITE = enable ? 1 : 0;
#else
    /* If not FLite->3AA OTF, FLite must be on */
    if (m_flagFlite3aaOTF == true) {
        m_requestFLITE = enable ? 1 : 0;
    } else {
        CLOGW("WRN(%s[%d]): isFlite3aaOtf (%d) == false). so Skip set m_requestFLITE(%d) as (%d)",
            __FUNCTION__, __LINE__, m_cameraId, m_requestFLITE, enable);
    }
#endif

}

void ExynosCamera3FrameFactory::setRequest3AC(bool enable)
{
#if 1
    m_request3AC = enable ? 1 : 0;
#else
    /* From 74xx, Front will use reprocessing. so, we need to prepare BDS */
    if (isReprocessing(m_cameraId) == true) {
        if (m_parameters->getUsePureBayerReprocessing() == true) {
            m_request3AC = 0;
        } else {
            m_request3AC = enable ? 1 : 0;
        }
    } else {
        m_request3AC = 0;
    }
#endif
}

void ExynosCamera3FrameFactory::setRequestISPC(bool enable)
{
    m_requestISPC = enable ? 1 : 0;
}

void ExynosCamera3FrameFactory::setRequestISPP(bool enable)
{
    m_requestISPP = enable ? 1 : 0;
}


void ExynosCamera3FrameFactory::setRequestSCC(bool enable)
{
    m_requestSCC = enable ? 1 : 0;
}

void ExynosCamera3FrameFactory::setRequestDIS(bool enable)
{
    m_requestDIS = enable ? 1 : 0;
}

status_t ExynosCamera3FrameFactory::getThreadState(int **threadState, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->getThreadState(threadState);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getThreadInterval(uint64_t **threadInterval, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->getThreadInterval(threadInterval);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::getThreadRenew(int **threadRenew, uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->getThreadRenew(threadRenew);

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::incThreadRenew(uint32_t pipeId)
{
    m_pipes[INDEX(pipeId)]->incThreadRenew();

    return NO_ERROR;
}

enum NODE_TYPE ExynosCamera3FrameFactory::getNodeType(uint32_t pipeId)
{
    enum NODE_TYPE nodeType = INVALID_NODE;

    switch (pipeId) {
    case PIPE_FLITE:
    case PIPE_FLITE_REPROCESSING:
        nodeType = CAPTURE_NODE_1;
        break;
    case PIPE_3AA:
    case PIPE_3AA_REPROCESSING:
        nodeType = OUTPUT_NODE;
        break;
    case PIPE_3AC:
    case PIPE_3AC_REPROCESSING:
        nodeType = CAPTURE_NODE_2;
        break;
    case PIPE_3AP:
    case PIPE_3AP_REPROCESSING:
        nodeType = m_flag3aaIspOTF ? OTF_NODE_1 : CAPTURE_NODE_3;
        break;
    case PIPE_ISP:
    case PIPE_ISP_REPROCESSING:
        nodeType = m_flag3aaIspOTF ? OTF_NODE_2 : OUTPUT_NODE;
        break;
    case PIPE_ISPC:
    case PIPE_ISPC_REPROCESSING:
        nodeType = CAPTURE_NODE_4;
        break;
    case PIPE_ISPP:
    case PIPE_ISPP_REPROCESSING:
        nodeType = (m_flagIspTpuOTF || m_flagIspMcscOTF) ? OTF_NODE_3 : CAPTURE_NODE_5;
        break;
    case PIPE_TPU:
        nodeType = m_flagIspTpuOTF ? OTF_NODE_4 : OUTPUT_NODE;
        break;
    case PIPE_TPUP:
        nodeType = m_flagIspTpuOTF ? OTF_NODE_5 : CAPTURE_NODE_6;
        break;
    case PIPE_MCSC:
    case PIPE_MCSC_REPROCESSING:
        nodeType = (m_flagIspMcscOTF || m_flagTpuMcscOTF) ? OTF_NODE_6 : OUTPUT_NODE;
        break;
    case PIPE_MCSC0:
    case PIPE_MCSC3_REPROCESSING:
        nodeType = CAPTURE_NODE_7;
        break;
    case PIPE_MCSC1:
    case PIPE_MCSC4_REPROCESSING:
        nodeType = CAPTURE_NODE_8;
        break;
    case PIPE_MCSC2:
    case PIPE_MCSC2_REPROCESSING:
        nodeType = CAPTURE_NODE_9;
        break;
    case PIPE_HWFC_JPEG_DST_REPROCESSING:
        nodeType = CAPTURE_NODE_10;
        break;
    case PIPE_HWFC_JPEG_SRC_REPROCESSING:
        nodeType = CAPTURE_NODE_11;
        break;
    case PIPE_HWFC_THUMB_SRC_REPROCESSING:
        nodeType = CAPTURE_NODE_12;
        break;
    case PIPE_HWFC_THUMB_DST_REPROCESSING:
        nodeType = CAPTURE_NODE_13;
        break;
    default:
        android_printAssert(NULL, LOG_TAG, "ASSERT(%s[%d]):Unexpected pipe_id(%d), assert!!!!",
            __FUNCTION__, __LINE__, pipeId);
        break;
    }

    return nodeType;
}

ExynosCameraFrame *ExynosCamera3FrameFactory::createNewFrameOnlyOnePipe(int pipeId, int frameCnt, uint32_t frameType)
{
    Mutex::Autolock lock(m_frameLock);
    status_t ret = NO_ERROR;
    ExynosCameraFrameEntity *newEntity[MAX_NUM_PIPES] = {};

    if (frameCnt < 0) {
        frameCnt = m_frameCount;
    }

    ExynosCameraFrame *frame = m_frameMgr->createFrame(m_parameters, frameCnt, frameType);

    /* set pipe to linkageList */
    newEntity[INDEX(pipeId)] = new ExynosCameraFrameEntity(pipeId, ENTITY_TYPE_INPUT_OUTPUT, ENTITY_BUFFER_FIXED);
    frame->addSiblingEntity(NULL, newEntity[INDEX(pipeId)]);

    return frame;
}

ExynosCameraFrame *ExynosCamera3FrameFactory::createNewFrameVideoOnly(void)
{
    status_t ret = NO_ERROR;
    ExynosCameraFrameEntity *newEntity[MAX_NUM_PIPES] = {};
    ExynosCameraFrame *frame = m_frameMgr->createFrame(m_parameters, m_frameCount);

    /* set GSC-Video pipe to linkageList */
    newEntity[INDEX(PIPE_GSC_VIDEO)] = new ExynosCameraFrameEntity(PIPE_GSC_VIDEO, ENTITY_TYPE_INPUT_OUTPUT, ENTITY_BUFFER_FIXED);
    frame->addSiblingEntity(NULL, newEntity[INDEX(PIPE_GSC_VIDEO)]);

    return frame;
}

void ExynosCamera3FrameFactory::dump()
{
    CLOGI("INFO(%s[%d]):", __FUNCTION__, __LINE__);

    for (int i = 0; i < MAX_NUM_PIPES; i++) {
        if (m_pipes[i] != NULL) {
            m_pipes[i]->dump();
        }
    }

    return;
}

status_t ExynosCamera3FrameFactory::dumpFimcIsInfo(uint32_t pipeId, bool bugOn)
{
    status_t ret = NO_ERROR;
    int pipeIdIsp = 0;

    if (m_pipes[INDEX(pipeId)] != NULL)
        ret = m_pipes[INDEX(pipeId)]->dumpFimcIsInfo(bugOn);
    else
        ALOGE("ERR(%s): pipe is not ready (%d/%d)", __FUNCTION__, pipeId, bugOn);

    return ret;
}

#ifdef MONITOR_LOG_SYNC
status_t ExynosCamera3FrameFactory::syncLog(uint32_t pipeId, uint32_t syncId)
{
    status_t ret = NO_ERROR;
    int pipeIdIsp = 0;

    if (m_pipes[INDEX(pipeId)] != NULL)
        ret = m_pipes[INDEX(pipeId)]->syncLog(syncId);
    else
        ALOGE("ERR(%s): pipe is not ready (%d/%d)", __FUNCTION__, pipeId, syncId);

    return ret;
}
#endif

status_t ExynosCamera3FrameFactory::setFrameCreateHandler(factory_handler_t handler)
{
    status_t ret = NO_ERROR;
    m_frameCreateHandler = handler;
    return ret;
}

factory_handler_t ExynosCamera3FrameFactory::getFrameCreateHandler()
{
    return m_frameCreateHandler;
}

bool ExynosCamera3FrameFactory::isCreated(void)
{
    Mutex::Autolock lock(m_stateLock);

    return (m_state == FRAME_FACTORY_STATE_CREATE)? true : false;
}

bool ExynosCamera3FrameFactory::isRunning(void)
{
    Mutex::Autolock lock(m_stateLock);

    return (m_state == FRAME_FACTORY_STATE_RUN)? true : false;
}

status_t ExynosCamera3FrameFactory::m_initFlitePipe(int sensorW, int sensorH, uint32_t frameRate)
{
    CLOGI("INFO(%s[%d])", __FUNCTION__, __LINE__);

    status_t ret = NO_ERROR;
    camera_pipe_info_t pipeInfo[MAX_NODE];

    int pipeId = PIPE_FLITE;
    /* FLITE is old pipe, node type is 0 */
    enum NODE_TYPE nodeType = (enum NODE_TYPE)0;
    enum NODE_TYPE leaderNodeType = OUTPUT_NODE;

    ExynosRect tempRect;
    struct ExynosConfigInfo *config = m_parameters->getConfig();
    int maxSensorW = 0, maxSensorH = 0, hwSensorW = 0, hwSensorH = 0;
    int bayerFormat = m_parameters->getBayerFormat(PIPE_FLITE);
    int perFramePos = 0;

#ifdef DEBUG_RAWDUMP
    if (m_parameters->checkBayerDumpEnable()) {
        bayerFormat = CAMERA_DUMP_BAYER_FORMAT;
    }
#endif

    CLOGI("INFO(%s[%d]):SensorSize(%dx%d)", __FUNCTION__, __LINE__, sensorW, sensorH);

    /* setParam for Frame rate : must after setInput on Flite */
    struct v4l2_streamparm streamParam;
    memset(&streamParam, 0x0, sizeof(v4l2_streamparm));

    streamParam.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    streamParam.parm.capture.timeperframe.numerator   = 1;
    streamParam.parm.capture.timeperframe.denominator = frameRate;
    CLOGI("INFO(%s[%d]:Set framerate (denominator=%d)", __FUNCTION__, __LINE__, frameRate);

    ret = setParam(&streamParam, pipeId);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):FLITE setParam fail, ret(%d)", __FUNCTION__, __LINE__, ret);
        return INVALID_OPERATION;
    }

    /* set v4l2 buffer size */
    tempRect.fullW = sensorW;
    tempRect.fullH = sensorH;
    tempRect.colorFormat = bayerFormat;

    /* set v4l2 video node bytes per plane */
    switch (bayerFormat) {
    case V4L2_PIX_FMT_SBGGR16:
        pipeInfo[nodeType].bytesPerPlane[0] = ROUND_UP((tempRect.fullW * 2), CAMERA_16PX_ALIGN);
        break;
    case V4L2_PIX_FMT_SBGGR12:
        pipeInfo[nodeType].bytesPerPlane[0] = ROUND_UP((tempRect.fullW * 3 / 2), CAMERA_16PX_ALIGN);
        break;
    case V4L2_PIX_FMT_SBGGR10:
        pipeInfo[nodeType].bytesPerPlane[0] = ROUND_UP((tempRect.fullW * 5 / 4), CAMERA_16PX_ALIGN);
        break;
    default:
        CLOGW("WRN(%s[%d]):Invalid bayer format(%d)", __FUNCTION__, __LINE__, bayerFormat);
        pipeInfo[nodeType].bytesPerPlane[0] = ROUND_UP((tempRect.fullW * 2), CAMERA_16PX_ALIGN);
        break;
    }

    /* set v4l2 video node buffer count */
    switch(m_parameters->getReprocessingBayerMode()) {
        case REPROCESSING_BAYER_MODE_PURE_ALWAYS_ON:
        case REPROCESSING_BAYER_MODE_PURE_DYNAMIC:
        case REPROCESSING_BAYER_MODE_DIRTY_ALWAYS_ON:
        case REPROCESSING_BAYER_MODE_DIRTY_DYNAMIC:
        case REPROCESSING_BAYER_MODE_NONE:
            pipeInfo[nodeType].bufInfo.count = config->current->bufInfo.num_sensor_buffers + config->current->bufInfo.num_bayer_buffers;
            break;
        default:
            CLOGE("ERR(%s[%d]):Invalid reprocessing mode(%d)", __FUNCTION__, __LINE__, m_parameters->getReprocessingBayerMode());
    }

    /* Set capture node default info */
    SET_CAPTURE_DEVICE_BASIC_INFO();

#ifdef SUPPORT_DEPTH_MAP
    if (m_parameters->getUseDepthMap()) {
        /* Depth Map Configuration */
        int depthMapW = 0, depthMapH = 0;
        int depthMapFormat = DEPTH_MAP_FORMAT;

        ret = m_parameters->getDepthMapSize(&depthMapW, &depthMapH);
        if (ret != NO_ERROR) {
            CLOGE("ERR(%s[%d]):Failed to getDepthMapSize", __FUNCTION__, __LINE__);
            return ret;
        }

        CLOGI("INFO(%s[%d]):DepthMapSize %dx%d",
                __FUNCTION__, __LINE__, depthMapW, depthMapH);

        tempRect.fullW = depthMapW;
        tempRect.fullH = depthMapH;
        tempRect.colorFormat = depthMapFormat;

        nodeType = CAPTURE_NODE_2;
        pipeInfo[nodeType].bytesPerPlane[0] = getBayerLineSize(tempRect.fullW, tempRect.colorFormat);
        pipeInfo[nodeType].bufInfo.count = config->current->bufInfo.num_sensor_buffers;

        SET_CAPTURE_DEVICE_BASIC_INFO();
    }
#endif

    ret = m_pipes[pipeId]->setupPipe(pipeInfo, m_sensorIds[pipeId]);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):FLITE setupPipe fail, ret(%d)", __FUNCTION__, __LINE__, ret);
        /* TODO: exception handling */
        return INVALID_OPERATION;
    }

    /* set BNS ratio */
    int bnsScaleRatio = 0;
    if (m_parameters->getUseFastenAeStable() == true
        || m_parameters->getHighSpeedRecording() == true
#ifdef USE_BINNING_MODE
        || m_parameters->getBinningMode() == true
#endif
    )
        bnsScaleRatio = 1000;
    else
        bnsScaleRatio = m_parameters->getBnsScaleRatio();

    ret = m_pipes[pipeId]->setControl(V4L2_CID_IS_S_BNS, bnsScaleRatio);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s[%d]):Set BNS(%.1f) fail, ret(%d)", __FUNCTION__, __LINE__,
                (float)(bnsScaleRatio / 1000), ret);
    } else {
        int bnsSize = 0;

        ret = m_pipes[pipeId]->getControl(V4L2_CID_IS_G_BNS_SIZE, &bnsSize);
        if (ret != NO_ERROR) {
            CLOGE("ERR(%s[%d]):Get BNS size fail, ret(%d)", __FUNCTION__, __LINE__, ret);
        } else {
            int bnsWidth = bnsSize >> 16;
            int bnsHeight = bnsSize & 0xffff;
            CLOGI("INFO(%s[%d]):BNS scale down ratio(%.1f), size (%dx%d)",
                    __FUNCTION__, __LINE__, (float)(bnsScaleRatio / 1000), bnsWidth, bnsHeight);

            m_parameters->setBnsSize(bnsWidth, bnsHeight);
        }
    }

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::m_initFrameMetadata(ExynosCameraFrame *frame)
{
    status_t ret = NO_ERROR;

    if (m_shot_ext == NULL) {
        CLOGE("ERR(%s[%d]): new struct camera2_shot_ext fail", __FUNCTION__, __LINE__);
        return INVALID_OPERATION;
    }

    memset(m_shot_ext, 0x0, sizeof(struct camera2_shot_ext));

    m_shot_ext->shot.magicNumber = SHOT_MAGIC_NUMBER;

    /* TODO: These bypass values are enabled at per-frame control */
    if (m_flagReprocessing == true) {
        frame->setRequest(PIPE_3AP_REPROCESSING, m_request3AP);
        frame->setRequest(PIPE_ISPC_REPROCESSING, m_requestISPC);
        frame->setRequest(PIPE_ISPP_REPROCESSING, m_requestISPP);
        if(m_supportSingleChain == true) {
            frame->setRequest(PIPE_MCSC2_REPROCESSING, m_requestMCSC2);
        }
        frame->setRequest(PIPE_MCSC3_REPROCESSING, m_requestMCSC3);
        frame->setRequest(PIPE_MCSC4_REPROCESSING, m_requestMCSC4);
        frame->setRequest(PIPE_HWFC_JPEG_SRC_REPROCESSING, m_requestJPEG);
        frame->setRequest(PIPE_HWFC_JPEG_DST_REPROCESSING, m_requestJPEG);
        frame->setRequest(PIPE_HWFC_THUMB_SRC_REPROCESSING, m_requestThumbnail);

        /* Reprocessing is not use this */
        m_bypassDRC = 1; /* m_parameters->getDrcEnable(); */
        m_bypassDNR = 1; /* m_parameters->getDnrEnable(); */
        m_bypassDIS = 1; /* m_parameters->getDisEnable(); */
        m_bypassFD = 1; /* m_parameters->getFdEnable(); */
    } else {
        frame->setRequest(PIPE_FLITE, m_requestFLITE);
        frame->setRequest(PIPE_VC1, m_requestVC1);
        frame->setRequest(PIPE_3AC, m_request3AC);
        frame->setRequest(PIPE_3AP, m_request3AP);
        frame->setRequest(PIPE_ISPC, m_requestISPC);
        frame->setRequest(PIPE_ISPP, m_requestISPP);
        frame->setRequest(PIPE_MCSC0, m_requestMCSC0);
        frame->setRequest(PIPE_MCSC1, m_requestMCSC1);
        frame->setRequest(PIPE_MCSC2, m_requestMCSC2);

        m_bypassDRC = m_parameters->getDrcEnable();
        m_bypassDNR = m_parameters->getDnrEnable();
        m_bypassDIS = m_parameters->getDisEnable();
        m_bypassFD = m_parameters->getFdEnable();
    }

    setMetaBypassDrc(m_shot_ext, m_bypassDRC);
    setMetaBypassDnr(m_shot_ext, m_bypassDNR);
    setMetaBypassDis(m_shot_ext, m_bypassDIS);
    setMetaBypassFd(m_shot_ext, m_bypassFD);

    ret = frame->initMetaData(m_shot_ext);
    if (ret != NO_ERROR)
        CLOGE("ERR(%s[%d]): initMetaData fail", __FUNCTION__, __LINE__);

    return ret;
}

status_t ExynosCamera3FrameFactory::m_initPipelines(ExynosCameraFrame *frame)
{
    ExynosCameraFrameEntity *curEntity = NULL;
    ExynosCameraFrameEntity *childEntity = NULL;
    frame_queue_t *frameQ = NULL;
    status_t ret = NO_ERROR;

    curEntity = frame->getFirstEntity();

    while (curEntity != NULL) {
        childEntity = curEntity->getNextEntity();
        if (childEntity != NULL) {
            ret = getInputFrameQToPipe(&frameQ, childEntity->getPipeId());
            if (ret != NO_ERROR || frameQ == NULL) {
                CLOGE("ERR(%s):getInputFrameQToPipe fail, ret(%d), frameQ(%p)", __FUNCTION__, ret, frameQ);
                return ret;
            }

            ret = setOutputFrameQToPipe(frameQ, curEntity->getPipeId());
            if (ret != NO_ERROR) {
                CLOGE("ERR(%s):setOutputFrameQToPipe fail, ret(%d)", __FUNCTION__, ret);
                return ret;
            }

            /* check Image Configuration Equality */
            ret = m_checkPipeInfo(curEntity->getPipeId(), childEntity->getPipeId());
            if (ret != NO_ERROR) {
                CLOGE("ERR(%s):checkPipeInfo fail, Pipe[%d], Pipe[%d]", __FUNCTION__, curEntity->getPipeId(), childEntity->getPipeId());
                return ret;
            }

            curEntity = childEntity;
        } else {
            curEntity = frame->getNextEntity();
        }
    }

    return NO_ERROR;
}

status_t ExynosCamera3FrameFactory::m_checkPipeInfo(uint32_t srcPipeId, uint32_t dstPipeId)
{
    int srcFullW, srcFullH, srcColorFormat;
    int dstFullW, dstFullH, dstColorFormat;
    int isDifferent = 0;
    status_t ret = NO_ERROR;

    ret = m_pipes[INDEX(srcPipeId)]->getPipeInfo(&srcFullW, &srcFullH, &srcColorFormat, SRC_PIPE);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s):Source getPipeInfo fail", __FUNCTION__);
        return ret;
    }
    ret = m_pipes[INDEX(dstPipeId)]->getPipeInfo(&dstFullW, &dstFullH, &dstColorFormat, DST_PIPE);
    if (ret != NO_ERROR) {
        CLOGE("ERR(%s):Destination getPipeInfo fail", __FUNCTION__);
        return ret;
    }

    if (srcFullW != dstFullW || srcFullH != dstFullH || srcColorFormat != dstColorFormat) {
        CLOGE("ERR(%s[%d]):Video Node Image Configuration is NOT matching. so, fail", __FUNCTION__, __LINE__);

        CLOGE("ERR(%s[%d]):fail info : srcPipeId(%d), srcFullW(%d), srcFullH(%d), srcColorFormat(%d)",
            __FUNCTION__, __LINE__, srcPipeId, srcFullW, srcFullH, srcColorFormat);

        CLOGE("ERR(%s[%d]):fail info : dstPipeId(%d), dstFullW(%d), dstFullH(%d), dstColorFormat(%d)",
            __FUNCTION__, __LINE__, dstPipeId, dstFullW, dstFullH, dstColorFormat);

        return INVALID_OPERATION;
    }

    return NO_ERROR;
}

int ExynosCamera3FrameFactory::m_getSensorId(__unused unsigned int nodeNum, bool reprocessing)
{
    unsigned int reprocessingBit = 0;
    unsigned int nodeNumBit = 0;
    unsigned int sensorIdBit = 0;
    unsigned int sensorId = getSensorId(m_cameraId);

    if (reprocessing == true)
        reprocessingBit = (1 << REPROCESSING_SHIFT);

    /*
     * hack
     * nodeNum - FIMC_IS_VIDEO_BAS_NUM is proper.
     * but, historically, FIMC_IS_VIDEO_SS0_NUM - FIMC_IS_VIDEO_SS0_NUM is worked properly
     */
    //nodeNumBit = ((nodeNum - FIMC_IS_VIDEO_BAS_NUM) << SSX_VINDEX_SHIFT);
    nodeNumBit = ((FIMC_IS_VIDEO_SS0_NUM - FIMC_IS_VIDEO_SS0_NUM) << SSX_VINDEX_SHIFT);

    sensorIdBit = (sensorId << 0);

    return (reprocessingBit) |
           (nodeNumBit) |
           (sensorIdBit);
}

int ExynosCamera3FrameFactory::m_getSensorId(unsigned int nodeNum, unsigned int connectionMode, bool flagLeader, bool reprocessing)
{
    /* sub 100, and make index */
    nodeNum -= 100;

    unsigned int reprocessingBit = 0;
    unsigned int otfInterfaceBit = 0;
    unsigned int leaderBit = 0;
    unsigned int sensorId = getSensorId(m_cameraId);

    if (reprocessing == true)
        reprocessingBit = 1;

    if (flagLeader == true)
        leaderBit = 1;

    return ((reprocessingBit    << INPUT_STREAM_SHIFT) & INPUT_STREAM_MASK) |
           ((sensorId           << INPUT_MODULE_SHIFT) & INPUT_MODULE_MASK) |
           ((nodeNum            << INPUT_VINDEX_SHIFT) & INPUT_VINDEX_MASK) |
           ((connectionMode     << INPUT_MEMORY_SHIFT) & INPUT_MEMORY_MASK) |
           ((leaderBit          << INPUT_LEADER_SHIFT) & INPUT_LEADER_MASK);
}

int ExynosCamera3FrameFactory::m_getFliteNodenum(void)
{
    int fliteNodeNum = FIMC_IS_VIDEO_SS0_NUM;

#ifdef SAMSUNG_COMPANION
    if(m_parameters->getUseCompanion() == true) {
        fliteNodeNum = FIMC_IS_VIDEO_SS0_NUM;
    } else
#endif
    {
        fliteNodeNum = (m_cameraId == CAMERA_ID_BACK) ? MAIN_CAMERA_FLITE_NUM : FRONT_CAMERA_FLITE_NUM;
    }

    return fliteNodeNum;
}

#ifdef SUPPORT_DEPTH_MAP
int ExynosCamera3FrameFactory::m_getDepthVcNodeNum(void)
{
    int depthVcNodeNum = FIMC_IS_VIDEO_SS0VC1_NUM;

#ifdef SAMSUNG_COMPANION
    if (m_parameters->getUseCompanion() == true) {
        depthVcNodeNum = FIMC_IS_VIDEO_SS0VC1_NUM;
    } else
#endif
    {
        depthVcNodeNum = (m_cameraId == CAMERA_ID_BACK) ? MAIN_CAMERA_DEPTH_VC_NUM : FRONT_CAMERA_DEPTH_VC_NUM;
    }

    return depthVcNodeNum;
}
#endif

void ExynosCamera3FrameFactory::m_initDeviceInfo(int pipeId)
{
    camera_device_info_t nullDeviceInfo;

    m_deviceInfo[pipeId] = nullDeviceInfo;

    for (int i = 0; i < MAX_NODE; i++) {
        // set nodeNum
        m_nodeNums[pipeId][i] = m_deviceInfo[pipeId].nodeNum[i];

        // set default sensorId
        m_sensorIds[pipeId][i]  = -1;
    }
}

status_t ExynosCamera3FrameFactory::m_transitState(frame_factory_state_t state)
{
    Mutex::Autolock lock(m_stateLock);

    CLOGV("DEBUG(%s[%d]):State transition. curState %d newState %d",
            __FUNCTION__, __LINE__, m_state, state);

    if (m_state == state) {
        CLOGI("INFO(%s[%d]):Skip state transition. curState %d",
                __FUNCTION__, __LINE__, m_state);
        return NO_ERROR;
    }

    switch (m_state) {
    case FRAME_FACTORY_STATE_NONE:
        if (state != FRAME_FACTORY_STATE_CREATE)
            goto ERR_EXIT;

        m_state = state;
        break;
    case FRAME_FACTORY_STATE_CREATE:
        if (state > FRAME_FACTORY_STATE_INIT)
            goto ERR_EXIT;

        m_state = state;
        break;
    case FRAME_FACTORY_STATE_INIT:
        if (state != FRAME_FACTORY_STATE_RUN)
            goto ERR_EXIT;

        m_state = state;
        break;
    case FRAME_FACTORY_STATE_RUN:
        if (state != FRAME_FACTORY_STATE_CREATE)
            goto ERR_EXIT;

        m_state = state;
        break;
    default:
        CLOGW("WARN(%s[%d]):Invalid curState %d maxValue %d",
                __FUNCTION__, __LINE__, state, FRAME_FACTORY_STATE_MAX);
        goto ERR_EXIT;
    }

    return NO_ERROR;

ERR_EXIT:
    CLOGE("ERR(%s[%d]):Invalid state transition. curState %d newState %d",
            __FUNCTION__, __LINE__, m_state, state);
    return INVALID_OPERATION;
}

void ExynosCamera3FrameFactory::m_init(void)
{
    m_cameraId = 0;
    m_frameCount = 0;

    m_shot_ext = new struct camera2_shot_ext;

    memset(m_name, 0x00, sizeof(m_name));
    memset(m_nodeNums, -1, sizeof(m_nodeNums));
    memset(m_sensorIds, -1, sizeof(m_sensorIds));

    for (int i = 0; i < MAX_NUM_PIPES; i++)
        m_pipes[i] = NULL;

    m_frameMgr = NULL;

    /* setting about request */
    m_requestFLITE = true;
    m_requestVC1 = false;
    m_requestVC2 = false;
    m_requestVC3 = false;

    m_request3AC = false;
    m_request3AP = false;

    m_requestISP = false;
    m_requestISPC = false;
    m_requestISPP = false;

    m_requestDIS = false;
    m_requestSCC = false;
    m_requestSCP = false;

    m_requestMCSC0 = false;
    m_requestMCSC1 = false;
    m_requestMCSC2 = false;
    m_requestMCSC3 = false;
    m_requestMCSC4 = false;

    m_requestJPEG = false;
    m_requestThumbnail = false;

    /* setting about bypass */
    m_bypassDRC = true;
    m_bypassDIS = true;
    m_bypassDNR = true;
    m_bypassFD = true;

    /* setting about H/W OTF mode */
    m_flagFlite3aaOTF = false;
    m_flag3aaIspOTF = false;
    m_flagIspTpuOTF = false;
    m_flagIspMcscOTF = false;
    m_flagTpuMcscOTF = false;

    /* setting about reprocessing */
    m_supportReprocessing = false;
    m_flagReprocessing = false;
    m_supportPureBayerReprocessing = false;
    m_supportSCC = false;
    m_supportSingleChain = false;

    m_state = FRAME_FACTORY_STATE_NONE;
}

}; /* namespace android */
