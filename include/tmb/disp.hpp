#ifndef _TMB_DISP_HPP_
#define _TMB_DISP_HPP_

class BlitMaster { // 0x1
    // BlitMaster& operator=();
    BlitMaster();
    ~BlitMaster();
    void blitToFrameBuffer();
    void blitToZBuffer();
    void loadShellTextureFile();
    void preloadShellTextureFile();
};

#endif // _TMB_DISP_HPP_
