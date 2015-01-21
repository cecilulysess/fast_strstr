module Paths_fast_strstr (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [0,0,0], versionTags = []}
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/julian/.cabal/bin"
libdir     = "/home/julian/.cabal/lib/x86_64-linux-ghc-7.6.3/fast-strstr-0.0.0"
datadir    = "/home/julian/.cabal/share/x86_64-linux-ghc-7.6.3/fast-strstr-0.0.0"
libexecdir = "/home/julian/.cabal/libexec"
sysconfdir = "/home/julian/.cabal/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "fast_strstr_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "fast_strstr_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "fast_strstr_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "fast_strstr_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "fast_strstr_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
