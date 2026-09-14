# DEMO2:

## construction complète à froid

D'apres mes recherches, une reconstruction complete a froid renvoie a remttre tout a zero, du coup, je vais d'abord verifier s'il y a encore un dosier buil avec la commande :
```
Test-Path .\Build
```
Je l'ai obtenu par mes recherches faites sur IA
 et cette commande renvoie **true** donc on va supprimer ce dossier et tout reprendre a zero, on supprime avec la commande:
 ```
 Remove-Item .\Build -Recurse -Force
 ```

 et quand on verifie avec la meme commande mentionner plus haut, ca renvoie **false** donc ca a bien ete executee

Maintenant on va remttre le workspace a zero depuis la commande:
```
jenga build
```
Resultat:
```

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkRecursiveMutex.cpp
✓   [2/12] Compiled: NkSemaphore.cpp
✓   [3/12] Compiled: NkSharedMutex.cpp
✓   [4/12] Compiled: NkLatch.cpp
✓   [5/12] Compiled: NkEvent.cpp
✓   [6/12] Compiled: NkBarrier.cpp
✓   [7/12] Compiled: NkMutex.cpp
✓   [8/12] Compiled: NkConditionVariable.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkSpinLock.cpp
✓   [11/12] Compiled: NkThreadPool.cpp
✓   [12/12] Compiled: NkReaderWriterLock.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKThreading.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLogLevel.cpp
✓   [2/14] Compiled: NkLoggerFormatter.cpp
✓   [3/14] Compiled: NkSink.cpp
✓   [4/14] Compiled: NkDistributingSink.cpp
✓   [5/14] Compiled: NkFileSink.cpp
✓   [6/14] Compiled: NkRegistry.cpp
✓   [7/14] Compiled: NkLogMessage.cpp
✓   [8/14] Compiled: NkLog.cpp
✓   [9/14] Compiled: NkDailyFileSink.cpp
✓   [10/14] Compiled: NkConsoleSink.cpp
✓   [11/14] Compiled: NkLogger.cpp
✓   [12/14] Compiled: NkAsyncSink.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKLogger.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.76s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeech                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkG2P.cpp
✓   [2/5] Compiled: NkTextNorm.cpp
✓   [3/5] Compiled: NkGriffinLim.cpp
✓   [4/5] Compiled: NkAudioFeatures.cpp
✓   [5/5] Compiled: NkVoiceSynth.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSpeech.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkCollisionWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCollision.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.61s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKReflection                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkType.cpp
✓   [2/7] Compiled: NkInspector.cpp
✓   [3/7] Compiled: NkClass.cpp
✓   [4/7] Compiled: NkMethod.cpp
✓   [5/7] Compiled: NkRegistry.cpp
✓   [6/7] Compiled: NkProperty.cpp
✓   [7/7] Compiled: NkReflection.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKReflection.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.69s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvolve                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkPopulation.cpp
✓   [2/2] Compiled: NkEvolution.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKEvolve.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.88s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontSizeCache.cpp
✓   [2/8] Compiled: NkFontRasterizer.cpp
✓   [3/8] Compiled: NkFontDetect.cpp
✓   [4/8] Compiled: NkFontParser.cpp
✓   [5/8] Compiled: NkUtils.cpp
✓   [6/8] Compiled: NkFontMesh.cpp
✓   [7/8] Compiled: NkFontAtlas.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFont.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.60s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKLogger\SandboxNKLogger.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.24s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
✓   [1/6] Compiled: NkPoseMass.cpp
✓   [2/6] Compiled: NkContactDetector.cpp
✓   [3/6] Compiled: NkAutoPose.cpp
✓   [4/6] Compiled: NkPoseBalancer.cpp
✓   [5/6] Compiled: NkBalance.cpp
✓   [6/6] Compiled: NkClipBalancePass.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKAnimPhysics.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.95s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkPath.cpp
✓   [2/5] Compiled: NkFileWatcher.cpp
✓   [3/5] Compiled: NkFileSystem.cpp
✓   [4/5] Compiled: NkFile.cpp
✓   [5/5] Compiled: NkDirectory.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKFileSystem.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.98s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkClock.cpp
✓   [2/8] Compiled: NkDuration.cpp
✓   [3/8] Compiled: NkDate.cpp
✓   [4/8] Compiled: NkTimeZone.cpp
✓   [5/8] Compiled: NkTimeSpan.cpp
✓   [6/8] Compiled: NkSystemClock.cpp
✓   [7/8] Compiled: NkChrono.cpp
✓   [8/8] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKTime.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeechTest                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKSpeechTest\NKSpeechTest.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.38s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkIntegrator.cpp
✓   [2/2] Compiled: NkPhysicsWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPhysics.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.68s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkNavMesh.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKNavigation.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKReflection                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled with warnings: main.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                      Warning: main.cpp                                       ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Sandbox\System\NKReflection\src\main.cpp:22:9: warning: offset of  ║
║ on non-standard-layout type 'SelfType' (aka '(anonymous namespace)::DemoObject')             ║
║ [-Winvalid-offsetof]                                                                         ║
║    22 |         NKENTSEU_REFLECT_PROPERTY(value)                                             ║
║       |         ^                         ~~~~~                                              ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKReflection\src/NKReflection/NkRegistry.h:525:49:   ║
║ note: expanded from macro 'NKENTSEU_REFLECT_PROPERTY'                                        ║
║ 525 | #define NKENTSEU_REFLECT_PROPERTY(PropertyName)                                        ║
║ NKENTSEU_REFLECT_PROPERTY_FLAGS(PropertyName, 0ULL)                                          ║
║ |                                                 ^                                          ║
║ ~~~~~~~~~~~~                                                                                 ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKReflection\src/NKReflection/NkRegistry.h:546:4:    ║
║ note: expanded from macro 'NKENTSEU_REFLECT_PROPERTY_FLAGS'                                  ║
║ 546 |                         offsetof(SelfType, PropertyName));                             ║
║ \                                                                                            ║
║       |                         ^                  ~~~~~~~~~~~~                              ║
║ C:/msys64/ucrt64/lib/clang/20/include/__stddef_offsetof.h:16:24: note: expanded from macro   ║
║ 'offsetof'                                                                                   ║
║    16 | #define offsetof(t, d) __builtin_offsetof(t, d)                                      ║
║       |                        ^                     ~                                       ║
║ 1 warning generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKReflection\SandboxNKReflection.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.95s  │
│ Warnings: 2                                                                                  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkConsoleStream.cpp
✓   [2/4] Compiled: NkBinaryStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKStream.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.32s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkBinaryReader.cpp
✓   [2/12] Compiled: NkJSONValue.cpp
✓   [3/12] Compiled: NkBinaryWriter.cpp
✓   [4/12] Compiled: NkJSONWriter.cpp
✓   [5/12] Compiled: NkJSONReader.cpp
✓   [6/12] Compiled: NkXMLWriter.cpp
✓   [7/12] Compiled: NkISerializable.cpp
✓   [8/12] Compiled: NkXMLReader.cpp
✓   [9/12] Compiled: NkYAMLReader.cpp
✓   [10/12] Compiled: NkArchive.cpp
✓   [11/12] Compiled: NkYAMLWriter.cpp
✓   [12/12] Compiled: NkReflectSerializer.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSerialization.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.39s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKFileSystem                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKFileSystem\SandboxNKFileSystem.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkMotionPath.cpp
✓   [2/4] Compiled: NkAnimationEditor.cpp
✓   [3/4] Compiled: NkAnimRetarget.cpp
✓   [4/4] Compiled: NkAnimation.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKAnimation.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.94s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓   [1/46] Compiled: NkSLCodeGenCPP.cpp
✓   [2/46] Compiled: NkSLCodeGenCPP.cpp
✓   [3/46] Compiled: NkSLCodeGenGLSLVulkan.cpp
✓   [4/46] Compiled: NkSLCodeGenGLSLVulkan.cpp
✓   [5/46] Compiled: NkSLCodeGenBytecode.cpp
✓   [6/46] Compiled: NkSLCodeGenBytecode.cpp
✓   [7/46] Compiled: NkSLCodeGenGLSL.cpp
✓   [8/46] Compiled: NkSLCodeGenGLSL.cpp
✓   [9/46] Compiled: NkSLCodeGenHLSL.cpp
✓   [10/46] Compiled: NkSLCodeGenHLSLStructs.cpp
✓   [11/46] Compiled: NkSLCodeGenHLSLStructs.cpp
✓   [12/46] Compiled: NkSLCodeGenHLSLDX12.cpp
✓   [13/46] Compiled: NkSLCodeGenMSL.cpp
✓   [14/46] Compiled: NkSLCodeGenHLSLDX12.cpp
✓   [15/46] Compiled: NkSLCodeGenMSL.cpp
✓   [16/46] Compiled: NkSLCodeGenHLSL.cpp
✓   [17/46] Compiled: NkSLCodeGenAdvanced.cpp
✓   [18/46] Compiled: NkSLCodeGenAdvanced.cpp
✓   [19/46] Compiled: NkSLLexer.cpp
✓   [20/46] Compiled: NkSLCodeGenMSLSpirvCross.cpp
✓   [21/46] Compiled: NkSLLexer.cpp
✓   [22/46] Compiled: NkSLCodeGenMSLSpirvCross.cpp
✓   [23/46] Compiled: NkSLParser.cpp
✓   [24/46] Compiled: NkSLParser.cpp
✓   [25/46] Compiled: NkSLFeatures.cpp
✓   [26/46] Compiled: NkSLFeatures.cpp
✓   [27/46] Compiled: NkSLSymbolTable.cpp
✓   [28/46] Compiled: NkSLSymbolTable.cpp
✓   [29/46] Compiled: NkSLSemantic.cpp
✓   [30/46] Compiled: NkSLSemantic.cpp
✓   [31/46] Compiled: NkSLCompiler.cpp
✓   [32/46] Compiled: NkSLCompiler.cpp
✓   [33/46] Compiled: NkSLReflector.cpp
✓   [34/46] Compiled: NkSLReflector.cpp
✓   [35/46] Compiled: NkGLSLCompiler.cpp
✓   [36/46] Compiled: NkSLByteCodeIO.cpp
✓   [37/46] Compiled: NkGLSLCompiler.cpp
✓   [38/46] Compiled: NkSLByteCodeIO.cpp
✓   [39/46] Compiled: NkSLVM.cpp
✓   [40/46] Compiled: NkSLVM.cpp
✓   [41/46] Compiled: NkShaderAnnotations.cpp
✓   [42/46] Compiled: NkShaderAnnotations.cpp
✓   [43/46] Compiled: NkShaderAnnotations.cpp
✓   [44/46] Compiled: NkShaderConvert.cpp
✓   [45/46] Compiled: NkShaderConvert.cpp
✓   [46/46] Compiled: NkShaderConvert.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKSL.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 9.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkNetDefines.cpp
✓   [2/10] Compiled: NkWebSocketServer.cpp
✓   [3/10] Compiled with warnings: NkReliableUDP.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkReliableUDP.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkReliableUDP.cpp: ║
║ 483:6: warning: ignoring return value of function declared with 'nodiscard' attribute        ║
║ [-Wunused-result]                                                                            ║
║ 483 |                                         mSocket->SendTo(buffer, NkRUDPHeader::kSize +  ║
║ entry->size, mRemote);                                                                       ║
║ |                                         ^~~~~~~~~~~~~~~                                    ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                           ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkReliableUDP.cpp: ║
║ 509:6: warning: ignoring return value of function declared with 'nodiscard' attribute        ║
║ [-Wunused-result]                                                                            ║
║ 509 |                                         mSocket->SendTo(buffer, NkRUDPHeader::kSize +  ║
║ entry->size, mRemote);                                                                       ║
║ |                                         ^~~~~~~~~~~~~~~                                    ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                           ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkReliableUDP.cpp: ║
║ 520:5: warning: ignoring return value of function declared with 'nodiscard' attribute        ║
║ [-Wunused-result]                                                                            ║
║   520 |                                 SendACK();                                           ║
║       |                                 ^~~~~~~                                              ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkReliableUDP.cpp: ║
║ 543:5: warning: ignoring return value of function declared with 'nodiscard' attribute        ║
║ [-Wunused-result]                                                                            ║
║ 543 |                                 mSocket->SendTo(buffer, NkRUDPHeader::kSize, mRemote); ║
║       |                                 ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║
║ 4 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [4/10] Compiled with warnings: NkSocket.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                    Warning: NkSocket.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkSocket.cpp:573:4 ║
║ : warning: ignoring return value of function declared with 'nodiscard' attribute             ║
║ [-Wunused-result]                                                                            ║
║   573 |                         SetSendBufferSize(kNkSendBufferSize);                        ║
║       |                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Transport\NkSocket.cpp:574:4 ║
║ : warning: ignoring return value of function declared with 'nodiscard' attribute             ║
║ [-Wunused-result]                                                                            ║
║   574 |                         SetRecvBufferSize(kNkRecvBufferSize);                        ║
║       |                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ 2 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [5/10] Compiled: NkRPC.cpp
✓   [6/10] Compiled: NkBitStream.cpp
✓   [7/10] Compiled: NkNetWorld.cpp
✓   [8/10] Compiled with warnings: NkLobby.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                     Warning: NkLobby.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:581:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║ 581 |                         mConnMgr.Broadcast(buffer, totalSize,                          ║
║ NkNetChannel::NK_NET_CHANNEL_RELIABLE_ORDERED);                                              ║
║       |                         ^~~~~~~~~~~~~~~~~~                                           ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:699:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║ 699 |                         mSession.GetConnMgr()->Broadcast(buffer,                       ║
║ NkLobbyMessageHeader::kSize + writer.BytesWritten(),                                         ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:770:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║ 770 |                         mSession.GetConnMgr()->Broadcast(buffer,                       ║
║ NkLobbyMessageHeader::kSize + writer.BytesWritten(),                                         ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:927:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║   927 |                         socket.SetBroadcast(true);                                   ║
║       |                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                     ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:968:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║   968 |                         socket.SetBroadcast(true);                                   ║
║       |                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                     ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobby\NkLobby.cpp:969:4:     ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║   969 |                         socket.SetNonBlocking(true);                                 ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~ ~~~~                                   ║
║ 6 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [9/10] Compiled with warnings: NkHTTPClient.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkHTTPClient.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP\NkHTTPClient.cpp:46:9:  ║
║ warning: 'NOMINMAX' macro redefined [-Wmacro-redefined]                                      ║
║    46 | #define NOMINMAX                                                                     ║
║       |         ^                                                                            ║
║ C:/msys64/ucrt64/include/c++/15.2.0/x86_64-w64-mingw32/bits/os_defines.h:45:9: note:         ║
║ previous definition is here                                                                  ║
║    45 | #define NOMINMAX 1                                                                   ║
║       |         ^                                                                            ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP\NkHTTPClient.cpp:891:4: ║
║ warning: ignoring return value of function declared with 'nodiscard' attribute               ║
║ [-Wunused-result]                                                                            ║
║   891 |                         ParseURL(req.url, scheme, host, port, path);                 ║
║       |                         ^~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                   ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP\NkHTTPClient.cpp:1316:4 ║
║ : warning: ignoring return value of function declared with 'nodiscard' attribute             ║
║ [-Wunused-result]                                                                            ║
║  1316 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1317 |                                 bool success = !resp.HasError() && resp.IsOK();      ║
║       |                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1318 |                                 if (cb) {                                            ║
║       |                                 ~~~~~~~~~                                            ║
║  1319 |                                         cb(success);                                 ║
║       |                                         ~~~~~~~~~~~~                                 ║
║  1320 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1321 |                         });                                                          ║
║       |                         ~                                                            ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP\NkHTTPClient.cpp:1333:4 ║
║ : warning: ignoring return value of function declared with 'nodiscard' attribute             ║
║ [-Wunused-result]                                                                            ║
║  1333 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1334 |                                 NkVector<NkLeaderboardEntry> entries;                ║
║       |                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                ║
║ 1335 |                                 if (!resp.HasError() && resp.IsOK() &&                ║
║ !resp.body.Empty()) {                                                                        ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                 ║
║ 1336 |                                         // Parsing JSON simplifié — en production     ║
║ utiliser un vrai parser                                                                      ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                            ║
║ 1337 |                                         // Exemple attendu :                          ║
║ [{"player":"Alice","score":1000,"rank":1},...]                                               ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                          ║
║  1338 |                                         ParseLeaderboardJSON(resp.body, entries);    ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    ║
║  1339 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1340 |                                 cb(entries);                                         ║
║       |                                 ~~~~~~~~~~~~                                         ║
║  1341 |                         });                                                          ║
║       |                         ~                                                            ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP\NkHTTPClient.cpp:1354:4 ║
║ : warning: ignoring return value of function declared with 'nodiscard' attribute             ║
║ [-Wunused-result]                                                                            ║
║  1354 |                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {      ║
║       |                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      ║
║  1355 |                                 uint32 rank = 0;                                     ║
║       |                                 ~~~~~~~~~~~~~~~~                                     ║
║  1356 |                                 uint64 score = 0;                                    ║
║       |                                 ~~~~~~~~~~~~~~~~~                                    ║
║ 1357 |                                 if (!resp.HasError() && resp.IsOK() &&                ║
║ !resp.body.Empty()) {                                                                        ║
║ |                                                                                            ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                 ║
║  1358 |                                         // Parsing JSON simplifié                    ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~                    ║
║  1359 |                                         ParsePlayerRankJSON(resp.body, rank, score); ║
║       |                                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║
║  1360 |                                 }                                                    ║
║       |                                 ~                                                    ║
║  1361 |                                 cb(rank, score);                                     ║
║       |                                 ~~~~~~~~~~~~~~~~                                     ║
║  1362 |                         });                                                          ║
║       |                         ~                                                            ║
║ 5 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [10/10] Compiled with warnings: NkConnection.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkConnection.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:82 ║
║ 0:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║ 820 |                         mRUDP.Send(buffer, NkSystemHeader::kSize,                      ║
║ NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);                                                    ║
║ |                         ^~~~~~~~~~                                                         ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                       ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:84 ║
║ 0:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║ 840 |                         mRUDP.Send(buffer, NkSystemHeader::kSize,                      ║
║ NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);                                                    ║
║ |                         ^~~~~~~~~~                                                         ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                       ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:91 ║
║ 6:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   916 |                         mSocket.SetNonBlocking(true);                                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:91 ║
║ 7:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   917 |                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:91 ║
║ 8:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   918 |                         mSocket.SetSendBufferSize(kNkSendBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:95 ║
║ 4:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   954 |                         mSocket.SetNonBlocking(true);                                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:95 ║
║ 5:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   955 |                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:95 ║
║ 6:4: warning: ignoring return value of function declared with 'nodiscard' attribute          ║
║ [-Wunused-result]                                                                            ║
║   956 |                         mSocket.SetSendBufferSize(kNkSendBufferSize);                ║
║       |                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                  ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:11 ║
║ 33:5: warning: ignoring return value of function declared with 'nodiscard' attribute         ║
║ [-Wunused-result]                                                                            ║
║  1133 |                                 conn->Disconnect(reason);                            ║
║       |                                 ^~~~~~~~~~~~~~~~ ~~~~~~                              ║
║ D:\Projets\Rihen\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Protocol\NkConnection.cpp:11 ║
║ 42:6: warning: ignoring return value of function declared with 'nodiscard' attribute         ║
║ [-Wunused-result]                                                                            ║
║  1142 |                                         mConnections[i]->Disconnect(reason);         ║
║       |                                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~           ║
║ 10 warnings generated.                                                                       ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKNetwork.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.18s  │
│ Warnings: 27                                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkKeyboardEvent.cpp
✓   [3/10] Compiled: NkMouseEvent.cpp
✓   [4/10] Compiled: NkEventState.cpp
✓   [5/10] Compiled: NkDropSystem.cpp
✓   [6/10] Compiled: NkWindowEvent.cpp
✓   [7/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [8/10] Compiled: NkEventDispatcher.cpp
✓   [9/10] Compiled: NkGamepadSystem.cpp
✓   [10/10] Compiled: NkEventSystem.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKEvent.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkNavCoreDemo\NkNavCoreDemo.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.50s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkBMPCodec.cpp
✓   [2/13] Compiled: NkPPMCodec.cpp
✓   [3/13] Compiled: NkTGACodec.cpp
✓   [4/13] Compiled: NkQOICodec.cpp
✓   [5/13] Compiled: NkGIFCodec.cpp
✓   [6/13] Compiled: NkICOCodec.cpp
✓   [7/13] Compiled: NkHDRCodec.cpp
✓   [8/13] Compiled: NkPNGCodec.cpp
✓   [9/13] Compiled: NkJPEGCodec.cpp
✓   [10/13] Compiled: NkEXRCodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKImage.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: FontLoad                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: main.cpp
✓   [2/2] Compiled: NkFont.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\FontLoad\FontLoad.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.56s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKECS                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkGameplayEventBus.cpp
✓   [2/2] Compiled: NkWorld.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKECS.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkSLCheck\NkSLCheck.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.75s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkSLComputeCheck\NkSLComputeCheck.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.71s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled with warnings: main.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                      Warning: main.cpp                                       ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Sandbox\System\NKNetwork\src\main.cpp:449:6: warning: format       ║
║ specifies type 'unsigned int' but the argument has type 'SizeType' (aka 'unsigned long       ║
║ long') [-Wformat]                                                                            ║
║ 448 |                 std::printf("[HTTPS] %s -> status=%u bodyLen=%u error='%s'\n",         ║
║ argv[2], resp.statusCode,                                                                    ║
║       |                                                              ~~                      ║
║       |                                                              %llu                    ║
║   449 |                                         resp.body.Length(), resp.error.CStr());      ║
║       |                                         ^~~~~~~~~~~~~~~~~~                           ║
║ 1 warning generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\SandboxNKNetwork\SandboxNKNetwork.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.74s  │
│ Warnings: 2                                                                                  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkWindowClipboardImage.cpp
✓   [3/9] Compiled: NkWindowCursor.cpp
✓   [4/9] Compiled: NkWindowClipboard.cpp
✓   [5/9] Compiled: NkDialogs.cpp
✓   [6/9] Compiled: NkContext.cpp
✓   [7/9] Compiled: NkWESystem.cpp
✓   [8/9] Compiled: NkWin32EventSystem.cpp
✓   [9/9] Compiled: NkWin32Window.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKWindow.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImageCodecTest                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKImageCodecTest\NKImageCodecTest.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUI                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 17 source file(s)
✓   [1/17] Compiled: NkUIAnimation.cpp
✓   [2/17] Compiled: NkUIMath.cpp
✓   [3/17] Compiled: NkUIDrawList.cpp
✓   [4/17] Compiled: NkUIRenderer.cpp
✓   [5/17] Compiled: NkUIFontBridge.cpp
✓   [6/17] Compiled: NkUIMenu.cpp
✓   [7/17] Compiled: NkUIContext.cpp
✓   [8/17] Compiled: NkUILayout.cpp
✓   [9/17] Compiled: NkUILayout2.cpp
✓   [10/17] Compiled: NkUIDock.cpp
✓   [11/17] Compiled: NkUIFont.cpp
✓   [12/17] Compiled: NkUIWindow.cpp
✓   [13/17] Compiled: NkUIWidgets.cpp
✓   [14/17] Compiled: NkUITree.cpp
✓   [15/17] Compiled: NkUIGizmo.cpp
✓   [16/17] Compiled: NkUIViewport3D.cpp
✓   [17/17] Compiled: NkUIFileBrowser.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKUI.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.72s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMedia                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 82 source file(s)
✓   [1/82] Compiled: NkAacHuffmanTables.cpp
✓   [2/82] Compiled: NkAacTns.cpp
✓   [3/82] Compiled: NkAacBitReader.cpp
✓   [4/82] Compiled: NkWavWriter.cpp
✓   [5/82] Compiled: NkAacHuffman.cpp
✓   [6/82] Compiled: NkCeltAlloc.cpp
✓   [7/82] Compiled: NkAacIcs.cpp
✓   [8/82] Compiled: NkAacDecoder.cpp
✓   [9/82] Compiled: NkAacTables.cpp
✓   [10/82] Compiled: NkAacDequant.cpp
✓   [11/82] Compiled: NkAacFilterbank.cpp
✓   [12/82] Compiled: NkCeltBands.cpp
✓   [13/82] Compiled: NkCeltDeemphasis.cpp
✓   [14/82] Compiled: NkCeltAntiCollapse.cpp
✓   [15/82] Compiled: NkCeltPvq.cpp
✓   [16/82] Compiled: NkCeltRate.cpp
✓   [17/82] Compiled: NkCeltEnergy.cpp
✓   [18/82] Compiled: NkCeltLaplace.cpp
✓   [19/82] Compiled: NkCeltDenorm.cpp
✓   [20/82] Compiled: NkOpusDecoder.cpp
✓   [21/82] Compiled: NkOpusPacket.cpp
✓   [22/82] Compiled: NkCeltDecoder.cpp
✓   [23/82] Compiled: NkCeltMdct.cpp
✓   [24/82] Compiled: NkCeltSplit.cpp
✓   [25/82] Compiled: NkCeltQuantBands.cpp
✓   [26/82] Compiled: NkOpusRange.cpp
✓   [27/82] Compiled: NkSilkDecoder.cpp
✓   [28/82] Compiled: NkSilkExcitationTables.cpp
✓   [29/82] Compiled: NkSilkExcitation.cpp
✓   [30/82] Compiled: NkSilkFrameType.cpp
✓   [31/82] Compiled: NkCeltVq.cpp
✓   [32/82] Compiled: NkSilkGains.cpp
✓   [33/82] Compiled: NkSilkIndices.cpp
✓   [34/82] Compiled: NkSilkIndicesTables.cpp
✓   [35/82] Compiled: NkSilkLpc.cpp
✓   [36/82] Compiled: NkSilkLtp.cpp
✓   [37/82] Compiled: NkSilkLtpTables.cpp
✓   [38/82] Compiled: NkSilkMath.cpp
✓   [39/82] Compiled: NkSilkNlsfTables.cpp
✓   [40/82] Compiled: NkSilkNlsf.cpp
✓   [41/82] Compiled: NkAmrDecoder.cpp
✓   [42/82] Compiled: NkSilkResampler.cpp
✓   [43/82] Compiled: NkSilkSynthesis.cpp
✓   [44/82] Compiled: NkSilkTop.cpp
✓   [45/82] Compiled: NkH264Transform.cpp
✓   [46/82] Compiled: NkHevcCabac.cpp
✓   [47/82] Compiled: NkH264Cavlc.cpp
✓   [48/82] Compiled: NkH264Decoder.cpp
✓   [49/82] Compiled: NkMpeg1Tables.cpp
✓   [50/82] Compiled: NkH264Encoder.cpp
✓   [51/82] Compiled: NkHevcDecoder.cpp
✓   [52/82] Compiled: NkOpusFile.cpp
✓   [53/82] Compiled: NkMpeg2Decoder.cpp
✓   [54/82] Compiled: NkMpeg1Encoder.cpp
✓   [55/82] Compiled: NkVp9Itxfm.cpp
✓   [56/82] Compiled: NkTheoraDecoder.cpp
✓   [57/82] Compiled: NkH264IntraDecoder.cpp
✓   [58/82] Compiled: NkVp8Decoder.cpp
✓   [59/82] Compiled: NkAv1Decoder.cpp
✓   [60/82] Compiled: NkMediaDemux.cpp
✓   [61/82] Compiled: NkMediaProbe.cpp
✓   [62/82] Compiled: NkVp9Decoder.cpp
✓   [63/82] Compiled: NkPdfInfo.cpp
✓   [64/82] Compiled: NkPdfGlyphList.cpp
✓   [65/82] Compiled: NkPdfShading.cpp
✓   [66/82] Compiled: NkPdfRaster.cpp
✓   [67/82] Compiled: NkAviWriter.cpp
✓   [68/82] Compiled: NkMovWriter.cpp
✓   [69/82] Compiled: NkWebmWriter.cpp
✓   [70/82] Compiled: NkMp4H264Writer.cpp
✓   [71/82] Compiled: NkHevcCtu.cpp
✓   [72/82] Compiled: NkPdf.cpp
✓   [73/82] Compiled: NkPdfColonnes.cpp
✓   [74/82] Compiled: NkPdfFont.cpp
✓   [75/82] Compiled: NkPdfLoad.cpp
✓   [76/82] Compiled: NkPdfStruct.cpp
✓   [77/82] Compiled: NkPdfRender.cpp
✓   [78/82] Compiled: NkVideoRecorder.cpp
✓   [79/82] Compiled: NkImageSequenceWriter.cpp
✓   [80/82] Compiled: NkVideoConverter.cpp
✓   [81/82] Compiled: NkVideoWriter.cpp
✓   [82/82] Compiled: NkVideoReader.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMedia.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.94s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGui                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkGuiIcons.cpp
✓   [2/5] Compiled: NkGuiFont.cpp
✓   [3/5] Compiled: NkGuiDrawList.cpp
✓   [4/5] Compiled: NkGuiContext.cpp
✓   [5/5] Compiled: NkGuiWidgets.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKGui.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.96s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKXR                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkXrConfigEnv.cpp
✓   [2/10] Compiled: NkArFlow.cpp
✓   [3/10] Compiled: NkArImu.cpp
✓   [4/10] Compiled: NkArCalibration.cpp
✓   [5/10] Compiled: NkArWorld.cpp
✓   [6/10] Compiled: NkArMarker.cpp
✓   [7/10] Compiled: NkArSession.cpp

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkXrOpenXRBackend.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\NkXrOpenXRBackend.cpp:30:10:  ║
║ fatal error: 'vulkan/vulkan.h' file not found                                                ║
║    30 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: D:\Projets\Rihen\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\NkXrOpenXRBackend.cpp
✓   [9/10] Compiled: NkXrSession.cpp
✓   [10/10] Compiled: NkXrSimulatorBackend.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 3.54s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  44/213
Failed:         1
Not reached:    168  (arret au premier echec — voir --keep-going)
Errors:         2
Warnings:       31
Time:           2m5.5s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKXR

```

### Temps relever de  la construction complete a froid
**Time:           2m5.5s**

## Construction complete a chaud

Ici on ne va rien changer car ceci consiste a faire une nouvelle construction sans toutefois remettre a zero, donc on va encore utiliser la meme construction que celle a froid
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

Build Order (213 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKGLSlang [STATIC_LIB] → 
  4. NKSPIRVCross [STATIC_LIB] → 
  5. NKMbedTLS [STATIC_LIB] → 
  6. pybind11 [STATIC_LIB] → 
  7. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  8. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  9. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  10. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  11. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  12. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  13. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  14. NKReflection [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  15. SandboxNKLogger [CONSOLE_APP] (depends: NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  16. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  17. NKSpeech [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  18. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  19. NKCollision [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  20. NKEvolve [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  21. NKAnimPhysics [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  22. SandboxNKReflection [CONSOLE_APP] (depends: NKReflection, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  23. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  24. NKSpeechTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKSpeech, NKThreading) → 
  25. NKNetwork [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  26. NKAnimation [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  27. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  28. NKSerialization [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKReflection, NKThreading) → 
  29. SandboxNKFileSystem [CONSOLE_APP] (depends: NKFileSystem, NKThreading, NKLogger, NKContainers, NKMemory, NKCore, NKPlatform) → 
  30. NKSL [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSPIRVCross, NKThreading) → 
  31. NKNavigation [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  32. NKPhysics [STATIC_LIB] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  33. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  34. SandboxNKNetwork [CONSOLE_APP] (depends: NKNetwork, NKTime, NKFileSystem, NKStream, NKMath, NKLogger, NKThreading, NKContainers, NKMemory, NKCore, NKPlatform) → 
  35. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  36. FontLoad [WINDOWED_APP] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  37. NKECS [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKThreading) → 
  38. NkSLComputeCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  39. NkSLCheck [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKGLSlang, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading) → 
  40. NkNavCoreDemo [CONSOLE_APP] (depends: NKCollision, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNavigation, NKPlatform, NKThreading) → 
  41. NKXR [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  42. NkImeTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime, NKWindow) → 
  43. NKRHI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  44. NKImageCodecTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  45. NKMedia [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  46. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  47. NKGui [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  48. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  49. NKTensor [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKThreading, NKTime, NKWindow) → 
  50. NkComputeNkSL [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  51. NkFontDemo [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  52. NKRenderer [STATIC_LIB] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  53. NkRHIDemoFullImage [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  54. NkSWRasterPrimitives [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  55. Model [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  56. NkRHIInterpTest [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  57. NkFDV2 [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  58. RendererRHI [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  59. NkRHIDemoFull [WINDOWED_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  60. NkGpuProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  61. NkPdfProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  62. NkPdfRasterTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  63. NkVideoReadTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  64. NKMediaTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  65. NkPdfRenderProbe [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  66. NKVideoTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  67. NKAudio [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  68. NkFileWorkerTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  69. NKUIIntegration [STATIC_LIB] (depends: NKUI, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  70. NKEditorKit [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  71. NKGuiDrawTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  72. NKGuiIntegration [STATIC_LIB] (depends: NKGui, NKRHI, NKSL, NKEvent, NKWindow, NKImage, NKFont, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKTime, NKStream, NKFileSystem, NKReflection, NKSerialization) → 
  73. Gamepad [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  74. NkSpriteDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  75. MonEssai [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKWindow) → 
  76. cr2d [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  77. Unkeny [STATIC_LIB] (depends: NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  78. NewGeneration [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  79. NKCamera [STATIC_LIB] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  80. NKRHIDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  81. NKImGuiIntegration [STATIC_LIB] (depends: NKCanvas, NKImage, NKFont, NKRHI, NKSL, NKEvent, NKWindow, NKMemory, NKCore, NKMath, NKContainers, NKLogger, NKPlatform, NKThreading, NKStream, NKTime, NKFileSystem, NKReflection, NKSerialization) → 
  82. firsttriangle [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  83. NkRef [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  84. Nkoung [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  85. NkCanvasDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  86. NKGuiDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKWindow) → 
  87. NkImageDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  88. NKViewportDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  89. ConquerorProto [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  90. NkDrawableDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  91. NKEvolveNNTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  92. NKData [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  93. NKEvolveTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKEvolve, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  94. NKGpuBenchTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  95. NkTensorGpuTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  96. NKTensorDemo [CONSOLE_APP] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  97. NKAutograd [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  98. NKXRDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  99. NKEditMeshHarness [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  100. Tuto02Renderer [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  101. Tuto01Fenetre [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  102. Tuto04Camera [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  103. gltftest [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  104. Tuto03Scene [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  105. Tuto05Meshes [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKAnimation, NKAnimPhysics, NKGLSlang, NKSPIRVCross) → 
  106. r2d01 [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross) → 
  107. NkFBXParityDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  108. NkAudioDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  109. Mou [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  110. NKOpusRef [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  111. RihenDefi [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  112. NkAudioPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  113. NkMicRecord [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  114. NKSpeechFeatureDemo [CONSOLE_APP] (depends: NKAudio, NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKSpeech, NKStream, NKThreading) → 
  115. NkDames [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  116. GemCrush [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  117. Pong [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  118. NkVideoPlayer [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow) → 
  119. NkLudo [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  120. NkEchecs [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  121. NkAnimPhysTest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAudio, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  122. NKCode [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  123. NKUIDesign [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  124. ConquerorLab [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow) → 
  125. NKEditorKitDemo [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKWindow) → 
  126. NKEditorKitTest [CONSOLE_APP] (depends: NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKReflection, NKStream, NKThreading, NKTime, NKWindow) → 
  127. NKPA [WINDOWED_APP] (depends: NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKThreading, NKTime, NKWindow, NKGuiIntegration) → 
  128. NK3DModeler [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKGuiIntegration) → 
  129. NkAnimaEditor [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCollision, NKContainers, NKCore, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKGuiIntegration) → 
  130. UnkenyEditor [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGlad, NKGui, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKReflection, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, Unkeny) → 
  131. NKARDemo [WINDOWED_APP] (depends: NKAnimPhysics, NKAnimation, NKCamera, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKThreading, NKTime, NKWindow, NKXR) → 
  132. NkCameraDemos [WINDOWED_APP] (depends: NKCamera, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  133. ImGuiRef [WINDOWED_APP] (depends: NKImGuiIntegration, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKWindow) → 
  134. NKDataTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  135. NKBpeTest [CONSOLE_APP] (depends: NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  136. NKNN [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  137. NKOptim [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  138. NKConvBenchTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  139. NKConvResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  140. NKInfer [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKTensor, NKThreading) → 
  141. NKGen [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKTensor, NKThreading) → 
  142. NKAutogradTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  143. NKConvTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  144. NKRebasinTransformer [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  145. NKGpt [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKFileSystem, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading, NKTime) → 
  146. NKRL [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  147. NKMlpResidentBench [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  148. NKFp16Test [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  149. NKTrain [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKData, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKTensor, NKThreading) → 
  150. NKNNTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  151. NKLlamaBlockTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  152. NKQwen2SftTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  153. NKQwenTokenizerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  154. NKQwen2BackwardTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  155. NKQwen2Train [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  156. NKQwen2SftGpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  157. NKQ4MatmulTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  158. NKQwen2GpuTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  159. NKQwen2Chat [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  160. NKLLMInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  161. NKGGUFInspectTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  162. NKQwen2Ask [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  163. renderdemo [WINDOWED_APP] (depends: NKMedia, NKEvent, NKWindow, NKGlad, NKLogger, NKMath, NKTime, NKStream, NKFileSystem, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKRenderer, NKAnimation, NKAnimPhysics, NKSL, NKSerialization, NKReflection, NKImage, NKFont, NKGLSlang, NKSPIRVCross, NKGen, NKNN, NKAutograd, NKTensor) → 
  164. NKEditTargetTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  165. NKGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  166. NKDiffusionTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  167. NKMatTypeResetTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  168. NKVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  169. NKObjectGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  170. NKGenMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  171. NKGen3DTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  172. NKMnistVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  173. NKConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  174. NKSmoothMeshTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  175. NKMnistConvVAETest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  176. NKVoxelGenTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  177. NKMeshRenderTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGen, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  178. NKRLTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  179. NKAgent [STATIC_LIB] (depends: NKAutograd, NKContainers, NKCore, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading, NKTime) → 
  180. NKTrainTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  181. NKIlyana [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGpt, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKNetwork, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  182. NKInferTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  183. NKMnistGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  184. NKMeshAITest [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  185. NKTTSTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  186. NKRnnCtcTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  187. NKGptTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  188. NkVoiceLoopDemo [CONSOLE_APP] (depends: NKAudio, NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  189. NKRebasinTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  190. NKTransformerTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKGpt, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  191. NKASRTest [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKSpeech, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  192. NKMnistCnnGpuTrain [CONSOLE_APP] (depends: NKAutograd, NKContainers, NKCore, NKData, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKLogger, NKMath, NKMemory, NKNN, NKOptim, NKPlatform, NKRHI, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKTrain, NKWindow) → 
  193. NKAgentLLMTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  194. NKAgentTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  195. NKCivilization [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKECS, NKFileSystem, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKReflection, NKSerialization, NKTensor, NKThreading) → 
  196. Noge [STATIC_LIB] (depends: NKGlad, NKMath, NKTime, NKLogger, NKEvent, NKWindow, NKContainers, NKMemory, NKCore, NKPlatform, NKThreading, NKRHI, NKSL, NKRenderer, NKCollision, NKPhysics, NKNavigation, NKSerialization, NKFileSystem, NKFont, NKImage, NKECS, NKRL, NKAgent, NKAudio, NKMedia, NKNetwork) → 
  197. NKEmbodied [STATIC_LIB] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRL, NKTensor, NKThreading) → 
  198. NKCivilizationTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  199. NKCivilizationScaleTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  200. NKCivilizationSocialTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKCivilization, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKReflection, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKWindow) → 
  201. NkAudioECSDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  202. NkHotReloadDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  203. NkNetWorldDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  204. NkUIHudDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  205. Nogee [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEditorKit, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  206. NkAssetIODemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  207. NkEditableMeshDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  208. NkLocomotionDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  209. PV3DE [WINDOWED_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAudio, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKGui, NKImage, NKInfer, NKLogger, NKMath, NKMedia, NKMemory, NKNavigation, NKNetwork, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKStream, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge, NKGuiIntegration) → 
  210. NkAgentEcsDemo [CONSOLE_APP] (depends: NKAgent, NKAnimPhysics, NKAnimation, NKAutograd, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKInfer, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKRL, NKReflection, NKRenderer, NKSL, NKSerialization, NKTensor, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  211. NkSVGImportDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSerialization, NKStream, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  212. NkNavDemo [CONSOLE_APP] (depends: NKAnimPhysics, NKAnimation, NKCanvas, NKCollision, NKContainers, NKCore, NKECS, NKEvent, NKFileSystem, NKFont, NKGLSlang, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKNavigation, NKPhysics, NKPlatform, NKRHI, NKReflection, NKRenderer, NKSL, NKSPIRVCross, NKSerialization, NKThreading, NKTime, NKUI, NKWindow, Noge) → 
  213. NKEmbodiedTest [CONSOLE_APP] (depends: NKAgent, NKAutograd, NKContainers, NKCore, NKEmbodied, NKEvent, NKFileSystem, NKGLSlang, NKGlad, NKInfer, NKLogger, NKMath, NKMemory, NKPlatform, NKRHI, NKRL, NKSL, NKSPIRVCross, NKStream, NKTensor, NKThreading, NKTime, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGLSlang                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 50 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.64s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSPIRVCross                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMbedTLS                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 109 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.28s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: pybind11                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project pybind11

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.41s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.19s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKReflection                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKLogger                                                 Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeech                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCollision                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvolve                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimPhysics                                                    Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 6 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.11s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKReflection                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.22s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSpeechTest                                                    Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAnimation                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSerialization                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKFileSystem                                             Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKSL                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 46 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.70s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNavigation                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPhysics                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.22s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: SandboxNKNetwork                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.29s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: FontLoad                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKECS                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLComputeCheck                                                Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSLCheck                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkNavCoreDemo                                                   Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKXR                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                           Compilation Error: NkXrOpenXRBackend.cpp                           ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ D:\Projets\Rihen\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\NkXrOpenXRBackend.cpp:30:10:  ║
║ fatal error: 'vulkan/vulkan.h' file not found                                                ║
║    30 | #include <vulkan/vulkan.h>                                                           ║
║       |          ^~~~~~~~~~~~~~~~~                                                           ║
║ 1 error generated.                                                                           ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: D:\Projets\Rihen\Nkentseu\Kernel\Runtime\NKXR\src\NKXR\Backend\NkXrOpenXRBackend.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 1.39s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  40/213
Failed:         1
Not reached:    172  (arret au premier echec — voir --keep-going)
Errors:         2
Time:           7.88s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKXR
```

### Temps relever de  la Construction complete a chaud
**Time:           7.88s**

## Construction d'un module
### NKMath

```
jenga build --target NKMath 
```
Resultat:

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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkTraits.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkFunction.cpp
✓   [4/14] Compiled: NkFunctionSIMD.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkProfiler.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkUtils.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkTracker.cpp
✓   [13/14] Compiled: NkTag.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkVector.cpp
✓   [2/43] Compiled: NkSet.cpp
✓   [3/43] Compiled: NkBinaryTree.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkArray.cpp
✓   [6/43] Compiled: NkPriorityQueue.cpp
✓   [7/43] Compiled: NkUnorderedMap.cpp
✓   [8/43] Compiled: NkInitializerList.cpp
✓   [9/43] Compiled: NkRingBuffer.cpp
✓   [10/43] Compiled: NkUnorderedSet.cpp
✓   [11/43] Compiled: NkBind.cpp
✓   [12/43] Compiled: NkFunctional.cpp
✓   [13/43] Compiled: NkTuple.cpp
✓   [14/43] Compiled: NkContainers.cpp
✓   [15/43] Compiled: NkPair.cpp
✓   [16/43] Compiled: NkFunction.cpp
✓   [17/43] Compiled: NkHashMap.cpp
✓   [18/43] Compiled: NkBTree.cpp
✓   [19/43] Compiled: NkQuadTree.cpp
✓   [20/43] Compiled: NkTrie.cpp
✓   [21/43] Compiled: NkPool.cpp
✓   [22/43] Compiled: NkIterator.cpp
✓   [23/43] Compiled: NkUTF16.cpp
✓   [24/43] Compiled: NkASCII.cpp
✓   [25/43] Compiled: NkGraph.cpp
✓   [26/43] Compiled: NkEncoding.cpp
✓   [27/43] Compiled: NkDeque.cpp
✓   [28/43] Compiled: NkDoubleList.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkList.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkOptional.cpp
✓   [35/43] Compiled: NkVariant.cpp
✓   [36/43] Compiled: NkSpan.cpp
✓   [37/43] Compiled: NkResult.cpp
✓   [38/43] Compiled: NkFormat.cpp
✓   [39/43] Compiled: NkString.cpp
✓   [40/43] Compiled: NkStringHash.cpp
✓   [41/43] Compiled: NkStringView.cpp
✓   [42/43] Compiled: NkStringBuilder.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.94s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkFunctions.cpp
✓   [2/12] Compiled: NkSIMD.cpp
✓   [3/12] Compiled: NkAngle.cpp
✓   [4/12] Compiled: NkEulerAngle.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkRange.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkRandom.cpp
✓   [9/12] Compiled: NkRectangle.cpp
✓   [10/12] Compiled: NkSegment.cpp
✓   [11/12] Compiled: NkColor.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           8.12s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```

### temps de construction du module NKMath
**Time:           8.12s**

## construction après modification d'un seul fichier source
### Cas de NKMath (fichier NKAnge (ajout d'un commentaire a la ligne 9))
Cette fois, on utilisera la commande suivante:
```
jenga build --target NKMath 
```
Resultat:
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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkCPUFeatures.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkTraits.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkContainerAllocator.cpp
✓   [4/14] Compiled: NkGc.cpp
✓   [5/14] Compiled: NkFunctionSIMD.cpp
✓   [6/14] Compiled: NkHash.cpp
✓   [7/14] Compiled: NkProfiler.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkUtils.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkTracker.cpp
✓   [13/14] Compiled: NkTag.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBind.cpp
✓   [2/43] Compiled: NkVector.cpp
✓   [3/43] Compiled: NkPool.cpp
✓   [4/43] Compiled: NkBinaryTree.cpp
✓   [5/43] Compiled: NkBTree.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkContainers.cpp
✓   [8/43] Compiled: NkFunction.cpp
✓   [9/43] Compiled: NkRingBuffer.cpp
✓   [10/43] Compiled: NkTuple.cpp
✓   [11/43] Compiled: NkArray.cpp
✓   [12/43] Compiled: NkIterator.cpp
✓   [13/43] Compiled: NkInitializerList.cpp
✓   [14/43] Compiled: NkPair.cpp
✓   [15/43] Compiled: NkTrie.cpp
✓   [16/43] Compiled: NkPriorityQueue.cpp
✓   [17/43] Compiled: NkMap.cpp
✓   [18/43] Compiled: NkUnorderedMap.cpp
✓   [19/43] Compiled: NkUnorderedSet.cpp
✓   [20/43] Compiled: NkHashMap.cpp
✓   [21/43] Compiled: NkFunctional.cpp
✓   [22/43] Compiled: NkASCII.cpp
✓   [23/43] Compiled: NkQuadTree.cpp
✓   [24/43] Compiled: NkEncoding.cpp
✓   [25/43] Compiled: NkUTF16.cpp
✓   [26/43] Compiled: NkGraph.cpp
✓   [27/43] Compiled: NkUTF32.cpp
✓   [28/43] Compiled: NkBase64.cpp
✓   [29/43] Compiled: NkDoubleList.cpp
✓   [30/43] Compiled: NkDeque.cpp
✓   [31/43] Compiled: NkList.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkOptional.cpp
✓   [35/43] Compiled: NkVariant.cpp
✓   [36/43] Compiled: NkSpan.cpp
✓   [37/43] Compiled: NkResult.cpp
✓   [38/43] Compiled: NkFormat.cpp
✓   [39/43] Compiled: NkStringHash.cpp
✓   [40/43] Compiled: NkString.cpp
✓   [41/43] Compiled: NkStringBuilder.cpp
✓   [42/43] Compiled: NkStringView.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.99s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkSIMD.cpp
✓   [2/12] Compiled: NkFunctions.cpp
✓   [3/12] Compiled: NkAngle.cpp
✓   [4/12] Compiled: NkEulerAngle.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkRange.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkRandom.cpp
✓   [9/12] Compiled: NkColor.cpp
✓   [10/12] Compiled: NkSegment.cpp
✓   [11/12] Compiled: NkRectangle.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.94s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           8.49s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


```
### Temps relever de  la construction après modification d'un seul fichier source
**Time:           8.49s**

## construction après modification d'un seul en-tête

ici je modifierai l'entete de NKAngle en ajoutant juste un commentaire
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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [4/12] Compiled: NkAngle.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkEulerAngle.cpp
✓   [7/12] Compiled: NkQuat.cpp
✓   [8/12] Compiled: NkRectangle.cpp
✓   [9/12] Compiled: NkColor.cpp
✓   [10/12] Compiled: NkRandom.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.76s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           2.35s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

```
### Temps relever de  la construction après modification d'un seul en-tête
**Time:           2.35s**

## Conclusion
### Temps relever de  la construction complete a froid
**Time:           2m5.5s**

### Temps relever de  la Construction complete a chaud
**Time:           7.88s**

### temps de construction du module NKMath

**Time:           8.12s**

### Temps relever de  la construction après modification d'un seul fichier source
**Time:           8.49s**

### Temps relever de  la construction après modification d'un seul en-tête
**Time:           2.35s**

## EXPLICATION
Après modification d’un seul fichier source .cpp (NKAngle.cpp), le temps de construction obtenu est de 8,49 s, tandis qu’après modification d’un fichier d’en-tête .h, il est de seulement 2,35 s. La modification du .cpp a donc pris plus de temps que celle du .h. Cette différence montre que le temps de reconstruction dépend des éléments que Jenga doit réellement recompiler. Même si un fichier .h peut avoir plusieurs fichiers dépendants, cela ne signifie pas forcément que sa modification entraînera une reconstruction plus longue. Dans notre cas, la modification du .h a entraîné moins de travail que celle du .cpp. Les dépendances jouent donc un rôle important dans le temps de reconstruction.