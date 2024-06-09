#ifndef FAR_CRY_FRAMEWORK_H
#define FAR_CRY_FRAMEWORK_H

class FarCryFramework
{
public:
    static void Initialize(void *graphicsDevice, const char *graphicsBackend);
    static void TickMainLoop(void *commandBufferPtr, void *backbufferDescriptor, int width, int height);
    static bool ShouldCloseWindow();
    static void Shutdown();

    static void ProcessMouseMove(float x, float y);
    static void ProcessKeyPress(char key, bool pressed);
};

#endif //FAR_CRY_FRAMEWORK_H
