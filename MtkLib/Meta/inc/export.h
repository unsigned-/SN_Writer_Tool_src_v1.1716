#ifndef __EXPORT_H__
#define __EXPORT_H__

#if defined(METACONN_EXPORTS) // inside DLL
#define METACONNAPI __declspec(dllexport) __stdcall
#else // outside DLL
#define METACONNAPI   __declspec(dllimport) __stdcall
#endif  // METACONN_EXPORTS

#endif