/*
 * ManyMouse main header. Include this from your app.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

#if !defined(__MINGW32__) && !defined(__MINGW32__) && !defined(_WIN32) && !defined(_WIN64)
#define __declspec(dllexport)
#endif

#ifndef _INCLUDE_MANYMOUSE_H_
#define _INCLUDE_MANYMOUSE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MANYMOUSE_VERSION "0.0.3"

typedef enum
{
    MANYMOUSE_EVENT_ABSMOTION = 0,
    MANYMOUSE_EVENT_RELMOTION,
    MANYMOUSE_EVENT_BUTTON,
    MANYMOUSE_EVENT_SCROLL,
    MANYMOUSE_EVENT_DISCONNECT,
    MANYMOUSE_EVENT_MAX
} ManyMouseEventType;

typedef struct
{
    ManyMouseEventType type;
    unsigned int device;
    unsigned int item;
    int value;
    int minval;
    int maxval;
} ManyMouseEvent;


/* internal use only. */
typedef struct
{
    const char *driver_name;
    int (*init)(void);
    void (*quit)(void);
    const char *(*name)(unsigned int index);
    int (*poll)(ManyMouseEvent *event);
} ManyMouseDriver;

__declspec(dllexport) int ManyMouse_Init(void);
__declspec(dllexport) const char *ManyMouse_DriverName(void);
__declspec(dllexport) void ManyMouse_Quit(void);
__declspec(dllexport) const char *ManyMouse_DeviceName(unsigned int index);
__declspec(dllexport) int ManyMouse_PollEvent(ManyMouseEvent *event);

#ifdef __cplusplus
}
#endif

#endif  /* !defined _INCLUDE_MANYMOUSE_H_ */

/* end of manymouse.h ... */

