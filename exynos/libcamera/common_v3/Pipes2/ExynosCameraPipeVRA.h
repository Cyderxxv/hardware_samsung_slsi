/*
**
** Copyright 2016, Samsung Electronics Co. LTD
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

#ifndef EXYNOS_CAMERA_PIPE_VRA_H
#define EXYNOS_CAMERA_PIPE_VRA_H

#include "ExynosCameraPipe.h"

namespace android {

typedef ExynosCameraList<ExynosCameraFrameSP_sptr_t> frame_queue_t;

class ExynosCameraPipeVRA : protected virtual ExynosCameraPipe {
public:
    ExynosCameraPipeVRA()
    {
        m_init();
    }

    ExynosCameraPipeVRA(
        int cameraId,
        ExynosCameraParameters *obj_param,
        bool isReprocessing,
        int32_t *nodeNums)  : ExynosCameraPipe(cameraId, obj_param, isReprocessing, nodeNums)
    {
        m_init();
    }

    virtual ~ExynosCameraPipeVRA();

    virtual status_t        create(int32_t *sensorIds = NULL);
    virtual status_t        destroy(void);

    virtual status_t        stop(void);

    virtual status_t        startThread(void);
    virtual status_t        stopThread(void);

    virtual status_t        getInputFrameQ(frame_queue_t **inputFrameQ);

protected:
    virtual bool            m_gscThreadFunc(void);
    virtual bool            m_mainThreadFunc(void);
    virtual status_t        m_runScaler(void);
    virtual status_t        m_putBuffer(void);

private:
    void                    m_init(void);

protected:
    sp<Thread>              m_gscThread;
    frame_queue_t          *m_gscFrameQ;
    frame_queue_t          *m_gscFrameDoneQ;
    ExynosCameraPipe       *m_gscPipe;
};

}; /* namespace android */

#endif
