//#include <config.h>
#include <unistd.h>

#if (defined _WIN32 || defined __WIN32__) && ! defined __CYGWIN__

/* FlushFileBuffers */
# define WIN32_LEAN_AND_MEAN
# include <windows.h>

# include <errno.h>

/* Get _get_osfhandle.  */
//# include "msvc-nothrow.h"

int
fsync (int fd)
{
  HANDLE h = (HANDLE) _get_osfhandle (fd);
  DWORD err;

  if (h == INVALID_HANDLE_VALUE)
    {
      errno = EBADF;
      return -1;
    }

  if (!FlushFileBuffers (h))
    {
      /* Translate some Windows errors into rough approximations of Unix
       * errors.  MSDN is useless as usual - in this case it doesn't
       * document the full range of errors.
       */
      err = GetLastError ();
      switch (err)
        {
          case ERROR_ACCESS_DENIED:
            /* For a read-only handle, fsync should succeed, even though we have
               no way to sync the access-time changes.  */
            return 0;

          /* eg. Trying to fsync a tty. */
          case ERROR_INVALID_HANDLE:
            errno = EINVAL;
          break;

          default:
            errno = EIO;
        }
      return -1;
    }

  return 0;
}

#else /* !Windows */

# error "This platform lacks fsync function, and Gnulib doesn't provide a replacement. This is a bug in Gnulib."

#endif /* !Windows */
