#include <unistd.h>
#include "Application.h"

#include "Task01.h"
#include "Task02.h"
#include "Task03.h"
#include "Task04.h"
#include "Task05_01.h"
#include "Task05_02.h"
#include "Task05_03.h"
#include "Task06.h"
#include "Task07.h"
#include "Task08.h"


// The application's entry point
int main(int argc, char ** argv)
{
	// Remember argc, argv
	{
		Application & app = Application::Instance();
		app.argc = argc;
		app.argv = argv;
	}

    //Task * pTask = new Task01();
    Task * pTask = new Task02();
    //Task * pTask = new Task03();
    //Task * pTask = new Task04();
    //Task * pTask = new Task05_01();
    //Task * pTask = new Task05_02();
    //Task * pTask = new Task05_03();
    //Task * pTask = new Task06();
	//Task * pTask = new Task07();
	//Task * pTask = new Task08();	
	{
		GraphicsEngine & engine = GraphicsEngine::Instance();

		engine.Init();
        pTask->Init();

		while (engine.IsRunning())
		{
            pTask->Update();
			engine.Render();
		}

        delete pTask;
		engine.Deinit();
    }
	
    return 0;
}
