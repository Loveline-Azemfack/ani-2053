# EXERCICE 10: _Prenez NKCanvas. Ouvrez son .jenga, relevez ses dépendances directes, puis celles de ses dépendances. Arrêtez-vous à deux niveaux et dessinez le graphe. Combien de projets faut-il construire avant lui ?_

Pour ceci, je suis d'abord aller essayer de localiser nkcanvas.jenga dasn mon explorateur windows, en ouvrant le dossier NKentseu, puis apres l'avoir localiser j'ai suivi l'idication  du chemin d'acces, et puis j'ai fais sa construction pour pouvoir afficher ses dependances avec la commandes suivantes:  
```
jenga build --target NKCanvas  
```  
et j'a obtenue ce resultat:  

```

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (16 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  13. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  14. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkCompilerDetect.cpp
✓   [2/7] Compiled: NkArchDetect.cpp
✓   [3/7] Compiled: NkCGXDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.00s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: wgl.c
✓   [2/2] Compiled: gl.c
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKGlad.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.80s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkTraits.cpp
✓   [3/5] Compiled: NkAssert.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkContainerAllocator.cpp
✓   [4/14] Compiled: NkGc.cpp
✓   [5/14] Compiled: NkHash.cpp
✓   [6/14] Compiled: NkFunctionSIMD.cpp
✓   [7/14] Compiled: NkProfiler.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkPoolAllocator.cpp
✓   [11/14] Compiled: NkUtils.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkEncoding.cpp
✓   [2/43] Compiled: NkInitializerList.cpp
✓   [3/43] Compiled: NkPriorityQueue.cpp
✓   [4/43] Compiled: NkContainers.cpp
✓   [5/43] Compiled: NkArray.cpp
✓   [6/43] Compiled: NkBTree.cpp
✓   [7/43] Compiled: NkBind.cpp
✓   [8/43] Compiled: NkSet.cpp
✓   [9/43] Compiled: NkASCII.cpp
✓   [10/43] Compiled: NkUnorderedMap.cpp
✓   [11/43] Compiled: NkGraph.cpp
✓   [12/43] Compiled: NkPair.cpp
✓   [13/43] Compiled: NkFunction.cpp
✓   [14/43] Compiled: NkTuple.cpp
✓   [15/43] Compiled: NkBinaryTree.cpp
✓   [16/43] Compiled: NkMap.cpp
✓   [17/43] Compiled: NkUnorderedSet.cpp
✓   [18/43] Compiled: NkIterator.cpp
✓   [19/43] Compiled: NkTrie.cpp
✓   [20/43] Compiled: NkQuadTree.cpp
✓   [21/43] Compiled: NkFunctional.cpp
✓   [22/43] Compiled: NkRingBuffer.cpp
✓   [23/43] Compiled: NkPool.cpp
✓   [24/43] Compiled: NkVector.cpp
✓   [25/43] Compiled: NkHashMap.cpp
✓   [26/43] Compiled: NkUTF16.cpp
✓   [27/43] Compiled: NkUTF32.cpp
✓   [28/43] Compiled: NkBase64.cpp
✓   [29/43] Compiled: NkUTF8.cpp
✓   [30/43] Compiled: NkDoubleList.cpp
✓   [31/43] Compiled: NkList.cpp
✓   [32/43] Compiled: NkDeque.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkOptional.cpp
✓   [35/43] Compiled: NkSpan.cpp
✓   [36/43] Compiled: NkFormat.cpp
✓   [37/43] Compiled: NkVariant.cpp
✓   [38/43] Compiled: NkResult.cpp
✓   [39/43] Compiled: NkStringHash.cpp
✓   [40/43] Compiled: NkString.cpp
✓   [41/43] Compiled: NkStringView.cpp
✓   [42/43] Compiled: NkStringBuilder.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkSIMD.cpp
✓   [2/12] Compiled: NkFunctions.cpp
✓   [3/12] Compiled: NkAngle.cpp
✓   [4/12] Compiled: NkEulerAngle.cpp
✓   [5/12] Compiled: NkRange.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkMat.cpp
✓   [8/12] Compiled: NkRandom.cpp
✓   [9/12] Compiled: NkRectangle.cpp
✓   [10/12] Compiled: NkColor.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.81s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkRecursiveMutex.cpp
✓   [2/12] Compiled: NkSemaphore.cpp
✓   [3/12] Compiled: NkSharedMutex.cpp
✓   [4/12] Compiled: NkEvent.cpp
✓   [5/12] Compiled: NkBarrier.cpp
✓   [6/12] Compiled: NkLatch.cpp
✓   [7/12] Compiled: NkConditionVariable.cpp
✓   [8/12] Compiled: NkMutex.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkSpinLock.cpp
✓   [11/12] Compiled: NkReaderWriterLock.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKThreading.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.25s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLoggerFormatter.cpp
✓   [3/14] Compiled: NkSink.cpp
✓   [4/14] Compiled: NkRegistry.cpp
✓   [5/14] Compiled: NkLog.cpp
✓   [6/14] Compiled: NkLogMessage.cpp
✓   [7/14] Compiled: NkDistributingSink.cpp
✓   [8/14] Compiled: NkLogger.cpp
✓   [9/14] Compiled: NkFileSink.cpp
✓   [10/14] Compiled: NkConsoleSink.cpp
✓   [11/14] Compiled: NkAsyncSink.cpp
✓   [12/14] Compiled: NkDailyFileSink.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKLogger.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.50s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkClock.cpp
✓   [2/8] Compiled: NkDate.cpp
✓   [3/8] Compiled: NkDuration.cpp
✓   [4/8] Compiled: NkTimeSpan.cpp
✓   [5/8] Compiled: NkTimeZone.cpp
✓   [6/8] Compiled: NkChrono.cpp
✓   [7/8] Compiled: NkSystemClock.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKTime.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontRasterizer.cpp
✓   [2/8] Compiled: NkFontDetect.cpp
✓   [3/8] Compiled: NkFontSizeCache.cpp
✓   [4/8] Compiled: NkFontParser.cpp
✓   [5/8] Compiled: NkUtils.cpp
✓   [6/8] Compiled: NkFontMesh.cpp
✓   [7/8] Compiled: NkFontAtlas.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFont.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.84s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkFileSystem.cpp
✓   [2/5] Compiled: NkFile.cpp
✓   [3/5] Compiled: NkFileWatcher.cpp
✓   [4/5] Compiled: NkPath.cpp
✓   [5/5] Compiled: NkDirectory.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFileSystem.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.94s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkDropSystem.cpp
✓   [3/10] Compiled: NkEventState.cpp
✓   [4/10] Compiled: NkMouseEvent.cpp
✓   [5/10] Compiled: NkKeyboardEvent.cpp
✓   [6/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [7/10] Compiled: NkWindowEvent.cpp
✓   [8/10] Compiled: NkEventDispatcher.cpp
✓   [9/10] Compiled: NkEventSystem.cpp
✓   [10/10] Compiled: NkGamepadSystem.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKEvent.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.00s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkBinaryStream.cpp
✓   [2/4] Compiled: NkConsoleStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKStream.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkDialogs.cpp
✓   [3/9] Compiled: NkContext.cpp
✓   [4/9] Compiled: NkWindowClipboard.cpp
✓   [5/9] Compiled: NkWindowClipboardImage.cpp
✓   [6/9] Compiled: NkWindowCursor.cpp
✓   [7/9] Compiled: NkWESystem.cpp
✓   [8/9] Compiled: NkWin32EventSystem.cpp
✓   [9/9] Compiled: NkWin32Window.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKWindow.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.84s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkBMPCodec.cpp
✓   [2/13] Compiled: NkHDRCodec.cpp
✓   [3/13] Compiled: NkGIFCodec.cpp
✓   [4/13] Compiled: NkICOCodec.cpp
✓   [5/13] Compiled: NkPPMCodec.cpp
✓   [6/13] Compiled: NkJPEGCodec.cpp
✓   [7/13] Compiled: NkQOICodec.cpp
✓   [8/13] Compiled: NkPNGCodec.cpp
✓   [9/13] Compiled: NkEXRCodec.cpp
✓   [10/13] Compiled: NkTGACodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKImage.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.61s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 31 source file(s)
✓   [1/31] Compiled: NkSoftwareComputeContext.cpp
✓   [2/31] Compiled: NkDX11ComputeContext.cpp
✓   [3/31] Compiled: NkDX12ComputeContext.cpp
✓   [4/31] Compiled: NkCanvasApp.cpp
✓   [5/31] Compiled: NkOpenGLContext.cpp
✓   [6/31] Compiled: NkDX11Renderer2D.cpp
✓   [7/31] Compiled: NkOpenGLComputeContext.cpp
✓   [8/31] Compiled: NkDX11Context.cpp
✓   [9/31] Compiled: NkDX12Renderer2D.cpp
✓   [10/31] Compiled: NkOpenGLRenderer2D.cpp
✓   [11/31] Compiled: NkDX12Context.cpp
✓   [12/31] Compiled: NkGpuPolicy.cpp
✓   [13/31] Compiled: NkVulkanRenderer2D.cpp
✓   [14/31] Compiled: NkVulkanComputeContext.cpp
✓   [15/31] Compiled: NkRenderer2DTypes.cpp
✓   [16/31] Compiled: NkBatchRenderer2D.cpp
✓   [17/31] Compiled: NkSoftwareContext.cpp
✓   [18/31] Compiled: NkFont.cpp
✓   [19/31] Compiled: NkVulkanContext.cpp
✓   [20/31] Compiled: NkSoftwareRenderer2D.cpp
✓   [21/31] Compiled: NkContextFactory.cpp
✓   [22/31] Compiled: NkRenderer2DFactory.cpp
✓   [23/31] Compiled: NkShape.cpp
✓   [24/31] Compiled: NkShader.cpp
✓   [25/31] Compiled: NkTexture.cpp
✓   [26/31] Compiled: NkSprite.cpp
✓   [27/31] Compiled: NkRenderTarget.cpp
✓   [28/31] Compiled: NkRenderTexture.cpp
✓   [29/31] Compiled: NkUICanvasBackend.cpp
✓   [30/31] Compiled: NkRenderWindow.cpp
✓   [31/31] Compiled: NkRenderWindowCapture.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCanvas.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.90s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  16/16
Time:           46.86s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```

## DEPENDANCES DIRECTS

Les dépendances directes de NKCanvas sont :
- NKContainers
- NKCore
- NKEvent
- NKFileSystem
- NKFont
- NKGlad
- NKImage
- NKLogger
- NKMath
- NKMemory
- NKPlatform
- NKStream
- NKThreading
- NKTime
- NKWindow

### DEPENDANCES DE SES DEPENDANCES A DEUX NIVEAUX

A deux niveaux, on releve les dependances de ses dependances et l'ensemble se resume a:

- NKPlatform, 
- NKCore, 
- NKMemory, 
- NKContainers, 
- NKMath,
- NKThreading, 
- NKLogger, 
- NKTime, 
- NKFont, 
- NKFileSystem,
- NKEvent, 
- NKStream, 
- NKWindow 
- NKImage.

Alors on denombre ici 14 autres dependances de ses dependances, pour rendre ceci plus explicite, on va faire un arbre qui traduit ces dependances:

## Graphe de l'ensemble des depndances a deux niveaux

```
NKCanvas
NKCanvas
├── NKContainers
│   ├── NKCore
│   ├── NKMemory
│   └── NKPlatform
│
├── NKCore
│   └── NKPlatform
│
├── NKEvent
│   ├── NKContainers
│   ├── NKCore
│   ├── NKLogger
│   ├── NKMath
│   ├── NKMemory
│   ├── NKPlatform
│   ├── NKThreading
│   ├── NKTime
│   └── ...
│
├── NKFileSystem
│   ├── NKContainers
│   ├── NKCore
│   ├── NKLogger
│   ├── NKMemory
│   ├── NKPlatform
│   └── NKThreading
│
├── NKFont
│   ├── NKContainers
│   ├── NKCore
│   ├── NKLogger
│   ├── NKMath
│   ├── NKMemory
│   ├── NKPlatform
│   └── NKThreading
│
├── NKGlad
│
├── NKImage
│   ├── NKContainers
│   ├── NKCore
│   ├── NKFileSystem
│   ├── NKLogger
│   ├── NKMath
│   ├── NKMemory
│   ├── NKPlatform
│   ├── NKStream
│   └── NKThreading
│
├── NKLogger
│   ├── NKContainers
│   ├── NKCore
│   ├── NKMemory
│   ├── NKPlatform
│   └── NKThreading
│
├── NKMath
│   ├── NKContainers
│   ├── NKCore
│   ├── NKMemory
│   └── NKPlatform
│
├── NKMemory
│   ├── NKCore
│   └── NKPlatform
│
├── NKPlatform
│
├── NKStream
│   ├── NKContainers
│   ├── NKCore
│   ├── NKFileSystem
│   ├── NKLogger
│   ├── NKMemory
│   ├── NKPlatform
│   └── NKThreading
│
├── NKThreading
│   ├── NKContainers
│   ├── NKCore
│   ├── NKMemory
│   └── NKPlatform
│
├── NKTime
│   ├── NKContainers
│   ├── NKCore
│   ├── NKLogger
│   ├── NKMemory
│   ├── NKPlatform
│   └── NKThreading
│
└── NKWindow
    ├── NKContainers
    ├── NKCore
    ├── NKEvent
    ├── NKFileSystem
    ├── NKLogger
    ├── NKMath
    ├── NKMemory
    ├── NKPlatform
    ├── NKStream
    ├── NKThreading
    └── NKTime
```
## Nombre de projets a construire avant lui

Avant de contruire donc NKCanvas il faut **15 projets** avant lui car il depend de ces 15 la.