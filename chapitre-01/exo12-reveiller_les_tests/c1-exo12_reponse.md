# EXERCICE 12: _Le workspace désactive la compilation des tests. Trouvez la ligne qui le fait, lancez malgré tout une suite de tests d'un module, et rendez : combien de suites existent, combien s'exécutent, combien passent._

## Ligne qui desactive la comilation des tests

```
dutc(enable=True)

dute(enable=True)
```
qui se trouve a la lig **451- 454** du fichier **NKentseu.jenga** et je l'ai retouver en lisant le fichier et en reperant les mots difficile en recherchant le role de ces mots et lorsque je suis tombee sur celui ci j'ai remarque que dutc signifie **Disable Unit Test compilation** qui empeche la compilation des tests unitaires. Quant a dute(enable = true) qui signifie **Disable Unit Test Execution** elle bloque l'execution des test.


## Lancement d'une suit de test d'un module

Dernierement lorsque j'ai tape **jenga info** il y avait une partie qui me parlait des tests donc on relance pour voir
```
jenga info
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

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
========================== Jenga Workspace: Nkentseu ===========================

Location: D:\Projets\Rihen\Nkentseu
Entry file: D:\Projets\Rihen\Nkentseu\Nkentseu.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Linux, macOS, Android, iOS, Web, HarmonyOS, XboxSeries, XboxOne
Target Architectures: x86_64, arm64, wasm32
Start project: Sandbox


Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
MonEssai                     WindowedApp   C++        No     Yes
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKPlatform                   StaticLib     C++        No     Yes
NKCore                       StaticLib     C++        No     Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKMemory                     StaticLib     C++        No     Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKFont                       StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKTime                       StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKThreading                  StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork                    StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKSerialization              StaticLib     C++        No     Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent                      StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas                     StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKUI                         StaticLib     C++        No     Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
Unkeny                       StaticLib     C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCamera                     StaticLib     C++        No     Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKCollision                  StaticLib     C++        No     Yes
NKPhysics                    StaticLib     C++        No     Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKNavigation                 StaticLib     C++        No     Yes
NKXR                         StaticLib     C++        No     Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
r2d01                        WindowedApp   C++        No     Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
firsttriangle                WindowedApp   C++        No     Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
renderdemo                   WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
Gamepad                      WindowedApp   C++        No     Yes
NkFontDemo                   WindowedApp   C++        No     Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
FontLoad                     WindowedApp   C++        No     Yes
RendererRHI                  WindowedApp   C++        No     Yes
gltftest                     WindowedApp   C++        No     Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
NewGeneration                WindowedApp   C++        No     Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
cr2d                         WindowedApp   C++        No     Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
NkFDV2                       WindowedApp   C++        No     Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKRenderer                   StaticLib     C++        No     Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKTensor                     StaticLib     C++        No     Yes
NKAutograd                   StaticLib     C++        No     Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKNN                         StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKOptim                      StaticLib     C++        No     Yes
NKData                       StaticLib     C++        No     Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKRL                         StaticLib     C++        No     Yes
NKAgent                      StaticLib     C++        No     Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKEvolve                     StaticLib     C++        No     Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKGen                        StaticLib     C++        No     Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
NKGpt                        StaticLib     C++        No     Yes
NKSpeech                     StaticLib     C++        No     Yes
NKTensorDemo                 ConsoleApp    C++        No     Yes
NkSLComputeCheck             ConsoleApp    C++        No     Yes
NkGpuProbe                   ConsoleApp    C++        No     Yes
NkComputeNkSL                ConsoleApp    C++        No     Yes
NkTensorGpuTest              ConsoleApp    C++        No     Yes
NKGpuBenchTest               ConsoleApp    C++        No     Yes
NKConvBenchTest              ConsoleApp    C++        No     Yes
NKConvResidentBench          ConsoleApp    C++        No     Yes
NKMlpResidentBench           ConsoleApp    C++        No     Yes
NKMnistGpuTrain              ConsoleApp    C++        No     Yes
NKRebasinTest                ConsoleApp    C++        No     Yes
NKMnistCnnGpuTrain           ConsoleApp    C++        No     Yes
NKTransformerTest            ConsoleApp    C++        No     Yes
NKGptTrain                   ConsoleApp    C++        No     Yes
NKIlyana                     ConsoleApp    C++        No     Yes
NKAutogradTest               ConsoleApp    C++        No     Yes
NKNNTest                     ConsoleApp    C++        No     Yes
NKConvTest                   ConsoleApp    C++        No     Yes
NKDataTest                   ConsoleApp    C++        No     Yes
NKBpeTest                    ConsoleApp    C++        No     Yes
NKLlamaBlockTest             ConsoleApp    C++        No     Yes
NKRebasinTransformer         ConsoleApp    C++        No     Yes
NKTrainTest                  ConsoleApp    C++        No     Yes
NKFp16Test                   ConsoleApp    C++        No     Yes
NKRnnCtcTest                 ConsoleApp    C++        No     Yes
NKASRTest                    ConsoleApp    C++        No     Yes
NKImageCodecTest             ConsoleApp    C++        No     Yes
NkEditableMeshDemo           ConsoleApp    C++        No     Yes
NkLocomotionDemo             ConsoleApp    C++        No     Yes
NkAssetIODemo                ConsoleApp    C++        No     Yes
NkFBXParityDemo              ConsoleApp    C++        No     Yes
NkSVGImportDemo              ConsoleApp    C++        No     Yes
NKMeshAITest                 ConsoleApp    C++        No     Yes
NKEditMeshHarness            ConsoleApp    C++        No     Yes
NkAnimPhysTest               ConsoleApp    C++        No     Yes
NkMicRecord                  ConsoleApp    C++        No     Yes
NKSpeechTest                 ConsoleApp    C++        No     Yes
NKTTSTrain                   ConsoleApp    C++        No     Yes
NkVoiceLoopDemo              ConsoleApp    C++        No     Yes
NKSpeechFeatureDemo          ConsoleApp    C++        No     Yes
NKMediaTest                  ConsoleApp    C++        No     Yes
NkVideoReadTest              ConsoleApp    C++        No     Yes
NkAudioPlayer                WindowedApp   C++        No     Yes
NkVideoPlayer                WindowedApp   C++        No     Yes
NKOpusRef                    ConsoleApp    C++        No     Yes
NKVideoTest                  ConsoleApp    C++        No     Yes
NKInferTest                  ConsoleApp    C++        No     Yes
NKGGUFInspectTest            ConsoleApp    C++        No     Yes
NKLLMInferTest               ConsoleApp    C++        No     Yes
NKQwenTokenizerTest          ConsoleApp    C++        No     Yes
NKQwen2BackwardTest          ConsoleApp    C++        No     Yes
NKQwen2SftTest               ConsoleApp    C++        No     Yes
NKQ4MatmulTest               ConsoleApp    C++        No     Yes
NKQwen2GpuTest               ConsoleApp    C++        No     Yes
NKQwen2Chat                  ConsoleApp    C++        No     Yes
NKQwen2SftGpuTest            ConsoleApp    C++        No     Yes
NKQwen2Train                 ConsoleApp    C++        No     Yes
NKQwen2Ask                   ConsoleApp    C++        No     Yes
NKRLTest                     ConsoleApp    C++        No     Yes
NKAgentTest                  ConsoleApp    C++        No     Yes
NKAgentLLMTest               ConsoleApp    C++        No     Yes
NkAgentEcsDemo               ConsoleApp    C++        No     Yes
NKEmbodiedTest               ConsoleApp    C++        No     Yes
NKEvolveTest                 ConsoleApp    C++        No     Yes
NKEvolveNNTest               ConsoleApp    C++        No     Yes
NKCivilizationTest           ConsoleApp    C++        No     Yes
NKCivilizationSocialTest     ConsoleApp    C++        No     Yes
NKCivilizationScaleTest      ConsoleApp    C++        No     Yes
NKGenTest                    ConsoleApp    C++        No     Yes
NKVAETest                    ConsoleApp    C++        No     Yes
NKMnistVAETest               ConsoleApp    C++        No     Yes
NKMnistConvVAETest           ConsoleApp    C++        No     Yes
NKConvVAETest                ConsoleApp    C++        No     Yes
NKDiffusionTest              ConsoleApp    C++        No     Yes
NKVoxelGenTest               ConsoleApp    C++        No     Yes
NKObjectGenTest              ConsoleApp    C++        No     Yes
NKGen3DTest                  ConsoleApp    C++        No     Yes
NKGenMeshTest                ConsoleApp    C++        No     Yes
NKSmoothMeshTest             ConsoleApp    C++        No     Yes
NKMatTypeResetTest           ConsoleApp    C++        No     Yes
NKEditTargetTest             ConsoleApp    C++        No     Yes
NKMeshRenderTest             ConsoleApp    C++        No     Yes
Model                        WindowedApp   C++        No     Yes
NkSLCheck                    ConsoleApp    C++        No     Yes
NKPA                         WindowedApp   C++        No     Yes
NKECS                        StaticLib     C++        No     Yes
NKECS_Tests                  TestSuite     C++        Yes    Yes
Noge                         StaticLib     C++        No     Yes
Noge_Tests                   TestSuite     C++        Yes    Yes
Nogee                        WindowedApp   C++        No     Yes
NKEditorKitDemo              WindowedApp   C++        No     Yes
NKEditorKitTest              ConsoleApp    C++        No     Yes
NKUIDesign                   WindowedApp   C++        No     Yes
ConquerorLab                 WindowedApp   C++        No     Yes
NkRef                        WindowedApp   C++        No     Yes
NkAnimaEditor                WindowedApp   C++        No     Yes
ImGuiRef                     WindowedApp   C++        No     Yes
NKGuiDrawTest                ConsoleApp    C++        No     Yes
NKGuiDemo                    WindowedApp   C++        No     Yes
NKViewportDemo               WindowedApp   C++        No     Yes
PV3DE                        WindowedApp   C++        No     Yes
Pong                         WindowedApp   C++        No     Yes
Nkoung                       WindowedApp   C++        No     Yes
Mou                          WindowedApp   C++        No     Yes
NkImeTest                    WindowedApp   C++        No     Yes
NkImageDemo                  WindowedApp   C++        No     Yes
RihenDefi                    WindowedApp   C++        No     Yes
NkAudioECSDemo               ConsoleApp    C++        No     Yes
NkNetWorldDemo               ConsoleApp    C++        No     Yes
NkNavDemo                    ConsoleApp    C++        No     Yes
NkNavCoreDemo                ConsoleApp    C++        No     Yes
NkHotReloadDemo              ConsoleApp    C++        No     Yes
NkUIHudDemo                  ConsoleApp    C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
NKXRDemo                     WindowedApp   C++        No     Yes
NKARDemo                     WindowedApp   C++        No     Yes
GemCrush                     WindowedApp   C++        No     Yes
NkDames                      WindowedApp   C++        No     Yes
NkEchecs                     WindowedApp   C++        No     Yes
NkLudo                       WindowedApp   C++        No     Yes
UnkenyEditor                 WindowedApp   C++        No     Yes


Available Toolchains
------------------------------------------------------------
Name                 Family   Target OS   Arch     Env    
==========================================================
host-clang           clang    Windows     x86_64   mingw
host-gcc             gcc      Windows     x86_64   mingw
msvc                 msvc     Windows     x86_64   msvc
clang-mingw          clang    Windows     x86_64   mingw
mingw                gcc      Windows     x86_64   mingw
clang-cross-linux    clang    Linux       x86_64   gnu
zig-linux-x86_64     clang    Linux       x86_64   gnu
zig-linux-x64        clang    Linux       x86_64   gnu
zig-windows-x86_64   clang    Windows     x86_64   mingw
zig-windows-x64      clang    Windows     x86_64   mingw
zig-macos-x86_64     clang    macOS       x86_64   gnu
zig-macos-arm64      clang    macOS       arm64    gnu
zig-ios-arm64        clang    iOS         arm64
zig-tvos-arm64       clang    tvOS        arm64
zig-watchos-arm64    clang    watchOS     arm64
zig-android-arm64    clang    Android     arm64    android
zig-web-wasm32       clang    Web         wasm32


Daemon
------------------------------------------------------------
Status: Not running

```

D'apres jenga info, les projets de types test sont au nombre de **60**
et elles sont entre autre:
- NKPlatform_Tests
- NKCore_Tests
- NKLogger_Tests
- NKMath_Tests
- NKMemory_Tests
- NKContainers_Tests
- NKImage_Tests
- NKFont_Tests
- NKAudio_Tests
- NKTime_Tests
- NKStream_Tests
- NKThreading_Tests
- NKFileSystem_Tests
- NKReflection_Tests
- NKNetwork_Tests
- NKSerialization_Tests
- NKEvent_Tests
- NKWindow_Tests
- NKCanvas_Tests
- NKRHI_Tests
- NKUI_Tests
- NKCamera_Tests
- NKCollision_Tests
- NKPhysics_Tests
- NKNavigation_Tests
- NKXR_Tests
- firsttriangle_Tests
- NkDrawableDemo_Tests
- gltftest_Tests
- NkRHIDemoFull_Tests
- NkCanvasDemo_Tests
- NkRHIDemoFullImage_Tests
- NkSpriteDemo_Tests
- renderdemo_Tests
- NKRHIDemo_Tests
- NkFDV2_Tests
- Gamepad_Tests
- NkSWRasterPrimitives_Tests
- NkFontDemo_Tests
- cr2d_Tests
- NkRHIInterpTest_Tests
- NewGeneration_Tests
- RendererRHI_Tests
- r2d01_Tests
- NKRenderer_Tests
- NKTensor_Tests
- NKAutograd_Tests
- NKNN_Tests
- NKOptim_Tests
- NKData_Tests
- NKTrain_Tests
- NKInfer_Tests
- NKRL_Tests
- NKAgent_Tests
- NKEvolve_Tests
- NKCivilization_Tests
- NKEmbodied_Tests
- NKGen_Tests
- NKECS_Tests
- Noge_Tests

## Cas du module NKMath
Lancons un peu la construction des test de ce module

```
jenga build --target NKMath_Tests 
```

lorsqu'on lance ceci, on remarque ceci:
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
✗ Unit-test compilation is disabled by workspace policy. Blocked target: 'NKMath_Tests'. Allow it with dutc(True, allow=['NKMath_Tests']) in the workspace, or lift the policy for this invocation with --force (jenga test/run) / --force-tests (jenga build).

┌──────────────────────────────────────────────────────────────────────────────┐
│ ERRORS (1)                                                                   │
├──────────────────────────────────────────────────────────────────────────────┤
│   1. Unit-test compilation is disabled by workspace policy. Blocked target:  │
│      'NKMath_Tests'. Allow it with dutc(True, allow=['NKMath_Tests']) in the │
│      workspace, or lift the policy for this invocation with --force (jenga   │
│      test/run) / --force-tests (jenga build).                                │
└──────────────────────────────────────────────────────────────────────────────┘
```

Donc on remaeque bien que la ligne de code qui bloque la compilation des tests a bien marcher. Pour ce fait, on va forcer le test avec la commande suivante:
```
jenga build --target NKMath_Tests --force-tests
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
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (7 projects):
  1. __Unitest__ [STATIC_LIB] →
  2. NKPlatform [STATIC_LIB] →
  3. NKCore [STATIC_LIB] (depends: NKPlatform) →
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform)→
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) →
  7. NKMath_Tests [TEST_SUITE] (depends: NKMath, __Unitest__, NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: TestLauncher.cpp
✓   [2/11] Compiled: TestAggregator.cpp
✓   [3/11] Compiled: TestCase.cpp
✓   [4/11] Compiled: TestAssert.cpp
✓   [5/11] Compiled: ConsoleReport.cpp
✓   [6/11] Compiled: Benchmark.cpp
✓   [7/11] Compiled: Profiler.cpp
✓   [8/11] Compiled: Unitest.cpp
✓   [9/11] Compiled: PerformanceReporter.cpp
✓   [10/11] Compiled: TestReporter.cpp
✓   [11/11] Compiled: TestRunner.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\__Unitest__\Unitest.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful           Time: 5.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

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
│  ✓ Build Successful                                                             Time: 1.35s  │
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
│  ✓ Build Successful           Time: 1.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkGlobalOperators.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkContainerAllocator.cpp
✓   [4/14] Compiled: NkFunctionSIMD.cpp
✓   [5/14] Compiled: NkGc.cpp
✓   [6/14] Compiled: NkHash.cpp
✓   [7/14] Compiled: NkProfiler.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkPoolAllocator.cpp
✓   [10/14] Compiled: NkMultiLevelAllocator.cpp
✓   [11/14] Compiled: NkUtils.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.51s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkArray.cpp
✓   [2/43] Compiled: NkEncoding.cpp
✓   [3/43] Compiled: NkBind.cpp
✓   [4/43] Compiled: NkFunctional.cpp
✓   [5/43] Compiled: NkBinaryTree.cpp
✓   [6/43] Compiled: NkUTF16.cpp
✓   [7/43] Compiled: NkBase64.cpp
✓   [8/43] Compiled: NkDoubleList.cpp
✓   [9/43] Compiled: NkPriorityQueue.cpp
✓   [10/43] Compiled: NkTrie.cpp
✓   [11/43] Compiled: NkFunction.cpp
✓   [12/43] Compiled: NkTuple.cpp
✓   [13/43] Compiled: NkPool.cpp
✓   [14/43] Compiled: NkASCII.cpp
✓   [15/43] Compiled: NkIterator.cpp
✓   [16/43] Compiled: NkVector.cpp
✓   [17/43] Compiled: NkQuadTree.cpp
✓   [18/43] Compiled: NkBTree.cpp
✓   [19/43] Compiled: NkSet.cpp
✓   [20/43] Compiled: NkList.cpp
✓   [21/43] Compiled: NkContainers.cpp
✓   [22/43] Compiled: NkPair.cpp
✓   [23/43] Compiled: NkUnorderedMap.cpp
✓   [24/43] Compiled: NkMap.cpp
✓   [25/43] Compiled: NkDeque.cpp
✓   [26/43] Compiled: NkRingBuffer.cpp
✓   [27/43] Compiled: NkHashMap.cpp
✓   [28/43] Compiled: NkUnorderedSet.cpp
✓   [29/43] Compiled: NkGraph.cpp
✓   [30/43] Compiled: NkInitializerList.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkOptional.cpp
✓   [35/43] Compiled: NkVariant.cpp
✓   [36/43] Compiled: NkResult.cpp
✓   [37/43] Compiled: NkFormat.cpp
✓   [38/43] Compiled: NkSpan.cpp
✓   [39/43] Compiled: NkStringHash.cpp
✓   [40/43] Compiled: NkString.cpp
✓   [41/43] Compiled: NkStringBuilder.cpp
✓   [42/43] Compiled: NkStringView.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.19s  │
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
│  ✓ Build Successful                                                             Time: 2.88s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath_Tests                                                     Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓   [1/3] Compiled: Entry.cpp
✓   [2/3] Compiled: benchmark_smoke.cpp
✓   [3/3] Compiled: test_smoke.cpp
ℹ Linking...
✓ Built: Build\Tests\Debug-Windows\NKMath_Tests.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.69s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED         
════════════════════════════════════════════════════════════════════════════════
Projects Built:  7/7
Time:           17.31s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

### combien de suites s'executent
Utilisons la commande:

```
jenga test --project NKMath_Tests --force
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

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
Building NKMath_Tests...
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
ℹ Workspace policy disableunittestcompilation lifted for this invocation (--force).

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (7 projects):
  1. __Unitest__ [STATIC_LIB] → 
  2. NKPlatform [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKMath_Tests [TEST_SUITE] (depends: NKMath, __Unitest__, NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: __Unitest__                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 11 source file(s)
✓   [1/11] Compiled: TestLauncher.cpp
✓   [2/11] Compiled: ConsoleReport.cpp
✓   [3/11] Compiled: TestAggregator.cpp
✓   [4/11] Compiled: TestAssert.cpp
✓   [5/11] Compiled: Benchmark.cpp
✓   [6/11] Compiled: TestCase.cpp
✓   [7/11] Compiled: Profiler.cpp
✓   [8/11] Compiled: Unitest.cpp
✓   [9/11] Compiled: PerformanceReporter.cpp
✓   [10/11] Compiled: TestReporter.cpp
✓   [11/11] Compiled: TestRunner.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\__Unitest__\Unitest.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.37s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkCPUFeatures.cpp
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.63s  │
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
│  ✓ Build Successful                                                             Time: 1.28s  │
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
✓   [6/14] Compiled: NkProfiler.cpp
✓   [7/14] Compiled: NkFunctionSIMD.cpp
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
│  ✓ Build Successful                                                             Time: 1.93s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkPriorityQueue.cpp
✓   [2/43] Compiled: NkUnorderedSet.cpp
✓   [3/43] Compiled: NkInitializerList.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkHashMap.cpp
✓   [6/43] Compiled: NkPair.cpp
✓   [7/43] Compiled: NkUnorderedMap.cpp
✓   [8/43] Compiled: NkSet.cpp
✓   [9/43] Compiled: NkFunctional.cpp
✓   [10/43] Compiled: NkPool.cpp
✓   [11/43] Compiled: NkTrie.cpp
✓   [12/43] Compiled: NkContainers.cpp
✓   [13/43] Compiled: NkBind.cpp
✓   [14/43] Compiled: NkFunction.cpp
✓   [15/43] Compiled: NkArray.cpp
✓   [16/43] Compiled: NkIterator.cpp
✓   [17/43] Compiled: NkTuple.cpp
✓   [18/43] Compiled: NkRingBuffer.cpp
✓   [19/43] Compiled: NkBTree.cpp
✓   [20/43] Compiled: NkBinaryTree.cpp
✓   [21/43] Compiled: NkVector.cpp
✓   [22/43] Compiled: NkASCII.cpp
✓   [23/43] Compiled: NkQuadTree.cpp
✓   [24/43] Compiled: NkGraph.cpp
✓   [25/43] Compiled: NkEncoding.cpp
✓   [26/43] Compiled: NkDoubleList.cpp
✓   [27/43] Compiled: NkDeque.cpp
✓   [28/43] Compiled: NkUTF16.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkUTF32.cpp
✓   [31/43] Compiled: NkList.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkOptional.cpp
✓   [35/43] Compiled: NkVariant.cpp
✓   [36/43] Compiled: NkResult.cpp
✓   [37/43] Compiled: NkSpan.cpp
✓   [38/43] Compiled: NkFormat.cpp
✓   [39/43] Compiled: NkStringHash.cpp
✓   [40/43] Compiled: NkStringView.cpp
✓   [41/43] Compiled: NkString.cpp
✓   [42/43] Compiled: NkStringBuilder.cpp
✓   [43/43] Compiled: NkStringUtils.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.62s  │
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
✓   [10/12] Compiled: NkColor.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.59s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath_Tests                                                     Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓   [1/3] Compiled: Entry.cpp
✓   [2/3] Compiled: benchmark_smoke.cpp
✓   [3/3] Compiled: test_smoke.cpp
ℹ Linking...
✓ Built: Build\Tests\Debug-Windows\NKMath_Tests.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  7/7
Time:           20.66s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


Running tests for NKMath_Tests...
╔======================================================================╗
║                                                                      ║
║      ██╗   ██╗███╗   ██╗██╗████████╗███████╗███████╗████████╗        ║
║      ██║   ██║████╗  ██║██║╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝        ║
║      ██║   ██║██╔██╗ ██║██║   ██║   █████╗  ███████╗   ██║           ║
║      ██║   ██║██║╚██╗██║██║   ██║   ██╔══╝  ╚════██║   ██║           ║
║      ╚██████╔╝██║ ╚████║██║   ██║   ███████╗███████║   ██║           ║
║       ╚═════╝ ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝           ║
║                                                                      ║
║                C++ Unit Testing Framework v1.0.0                     ║
║              Fast, Reliable, and Developer-Friendly                  ║
║                                                                      ║
║  Number of tests: 8                                                  ║
║  Verbose mode: enabled                                               ║
║  Colors: enabled                                                     ║
║  Progress bar: disabled                                              ║
║                                                                      ║
║               Session started: 2026-09-14 05:53:40                   ║
║                                                                      ║
╚======================================================================╝

[INF] D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\tests\benchmark_smoke.cpp:41 [NKMath Benchmark] NkMath vs std::sin/std::cos
[INF] D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\tests\benchmark_smoke.cpp:42   NkMath : 34000000.00 ns total (sink=1417.257080)
[INF] D:\Projets\Rihen\Nkentseu\Kernel\Foundation\NKMath\tests\benchmark_smoke.cpp:43   STL    : 15000000.00 ns total (sink=1417.225098)
✓ NKMathBenchmark_TrigonometryLoopVsStd         [OK]  3/3 assertions  (68ms)
  ✓ 3 assertion(s) réussie(s) (moy: 22ms/assert)
✓ NKmathmoke_BitAndIntegerUtilities             [OK]  7/7 assertions  (< 1ms)
  ✓ 7 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_DivisionAndInterpolationEdges      [OK]  10/10 assertions  (< 1ms)
  ✓ 10 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionComposition              [OK]  28/28 assertions  (< 1ms)
  ✓ 28 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionRotateVector             [OK]  184/184 assertions  (< 1ms)
  ✓ 184 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_QuaternionToMatrix                 [OK]  259/259 assertions  (< 1ms)
  ✓ 259 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_ScalarFunctions                    [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)
✓ NKmathmoke_VectorAndRectTypes                 [OK]  4/4 assertions  (< 1ms)
  ✓ 4 assertion(s) réussie(s) (moy: < 1ms/assert)


┌────────────────────── RÉSULTATS DES TESTS ──────────────────────┐
│ SUCCÈS                                                          │
├─────────────────────────────────────────────────────────────────┤
│ Tests :      8 réussis, 8 au total          │
│ Assertions : 499 réussies, 499 au total         │
│ Taux succès : Tests: 100.0%, Assertions: 100.0%        │
│ Temps total : 69ms (8ms/test)     │
└──────────────────────────────────────────────────────────────┘

✅ Tous les tests sont réussis !

All tests passed for NKMath_Tests.
```

### Tests executees et Test reussi

Avec ce resultat, on remarque que dans NKMath_tests, on a pu executer 8 test et tout les 8 tests ont reussi et l'esecution nous a coute en temos 69ms, soit 8ms par test


**CONCLUSION**
Alors dans Nkentseu.jenga, il existe **au total 60 test** le module NKMath compte **8 tests** et les **8tests ont bient ete executees et reussis.** et tout ceci est juste cacher a cause d ela ligne 
```
dutc(enable=True)

    dute(enable=True)
```

dont la premiere bloque la compilation et la seconde l'execution
