#include "app.h"
/*******************************************************************************************/
using namespace Engine;
App::App()
{
	load();
	init();
	while(!mEnd)
	{
		mCurrentTime = SDL_GetTicks();
		
		//mPastTimeCounter++;
		if(mCurrentTime - mPastTimeCounter >= 100)
		{
			run_keys();
			run();
			render();
			mPastTimeCounter = mCurrentTime;
		}	



		SDL_Delay(2);
	}
	quit();

}

/*******************************************************************************************/
void App::load()
{
	mEnd = false;
	mCurrentTime = SDL_GetTicks();
	mPastTimeCounter = SDL_GetTicks();
	
	//Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return;  
    }

	mScreen = SDL_SetVideoMode( 800, 600, 32, SDL_SWSURFACE ); //Ustaw wymiary okna
	
	SDL_WM_SetCaption( "ImageConverter", NULL ); //Ustaw tytul

	SDL_EnableKeyRepeat(5,SDL_DEFAULT_REPEAT_DELAY/4);


	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 0, 0, 8000, 1024, TRUE);

	freopen("CON", "w", stdout); // redirects stdout
	freopen("CON", "w", stderr); // redirects stderr

	printf("[App] Function LOAD - APP started\n");

}

void App::init()
{
	printf("[App] Function INIT - APP restarted\n");

}


/*******************************************************************************************/

void App::run_keys()
{
	   while( SDL_PollEvent( &mKeyEvent ) )
        {
			if(mKeyEvent.type == SDL_KEYDOWN)
			{
				switch(mKeyEvent.key.keysym.sym)
				{

					case SDLK_ESCAPE: 
						mEnd = true;
					break;
				}
			}	

			if(mKeyEvent.type == SDL_QUIT)
			{
				exit(0);
			}
			

	   }
		
}

/*******************************************************************************************/

void App::run()
{


}

/*******************************************************************************************/

void App::render()
{
	// rysuj biale tlo
	SDL_FillRect( mScreen, &mScreen->clip_rect, SDL_MapRGB( mScreen->format, 0xFF, 0xFF, 0xFF ) );


	

	//Aktualizuj obraz
    SDL_Flip( mScreen );
}

/*******************************************************************************************/

void App::quit()
{
	//Posprzataj

    //Wyjdz z SDL
    SDL_Quit();
}

/*******************************************************************************************/

App::~App()
{
	quit();
}


