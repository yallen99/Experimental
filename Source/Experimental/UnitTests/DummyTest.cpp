
BEGIN_DEFINE_SPEC(Dummy_One, "ProjectName.DummyTestCategory", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
int Index = 100;
int Decrement = 1;
END_DEFINE_SPEC(Dummy_One)

void Dummy_One::Define()
{
    // Code to run before each tests
    BeforeEach([this]()
    {
        // Normally I will initialize variables here
        // Note: Try not to do any test in this scope as `BeforeEach` is not meant to test any expectation,
        // do read the unreal link I provided for more information
        Index = 100;
    });

    // Code to run after each tests
    AfterEach([this]()
    {
        // Normally I would do any clean up her
    });

    // Describe doesn't really do anything, literally just 'describe' the string in the output log
    Describe("Fire Function", [this]()
    {
        /* In Unreal Document, `It` is literally means it. In this case, `It` means "Fire Function".
        *  So in the log, this will show : Fire Function.Should shoot one bullet out.
        *  My practice is to describe the `It` in full sentence. Something like "ShootBullet should only fire one bullet out."
        * It really depends on how you want to do it that will make thing easier to you and your team. At least in my opinion, there isn't any wrong or correct way to do it.
        */
        
        It("Should decrease index by 1", [this]()
        {
           
            Index -= Decrement;
            
            // There are different TestX function provided. You may want to look at them in the AutomationTest file. Or maybe AutomationCommon file. Example: TestFalse, TestNotEqual, TestNull etc.
            // Assuming there are some variables created in ShooterClass
            TestEqual("Index should only decrease by 1", Index, 99);
            TestTrue("Index should be 99", Index==99);
            // TestNotNull("Test for something to not be nullptr", SomePointer);
        });
        
        // Another test that related to the Fire Function can be put here. I will just leave it blank here
        It("", [this]()
        {
            
        });
    });
    
    Describe("Reload Function", [this]()
    {
        // Tests that related to the Reload Function can be put here. I will just leave it blank here
        It("", [this]()
        {
            
        });
    });
    
    
    Describe("Shoot Skill Function", [this]()
    {
        /** Latent function - Function that runs for few ticks
         *  Sometimes your function needs to runs for few frames, latent test can be used for its test
         *  Example: Skill that tells player how many enemies still alive
         *  Similar to `It` function with extra parameter that let you do something in another thread
         *  Generally I just do it in GameThread
         *  FDoneDelegate YourVariableName : basically just for the engine to know if the latent test finishes the job
         */
        LatentIt("HealthCheckSkill from Shoot Skill", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
        {
            // Because latent test runs on a separate thread we have to ensure that game logic tests run on a Game Thread. 
            AsyncTask(ENamedThreads::GameThread, [this]() 
            {
                Index = 100;
                Index -= Decrement;

                TestTrue("Index decreased.", Index < 100);
            });

            // Wait for X second. Let's say 1.0f second.
            FPlatformProcess::Sleep(1.0f);

            // Again, GameThread
            AsyncTask(ENamedThreads::GameThread, [this]() 
            {
                // You may do something here
                // In this example, I will straight jump to the test part
                // TestEqual("X number of enemies left.", ShooterA->NumberOfEnemiesLeft, X);
            });

            // This will delegate to inform Unreal Automation System that the latent function has finished.
            // So it will run other stuff. If I am not wrong, `latent functions` normally will only run after all the non-latent functions.
            TestDone.Execute();
        });
    });
}