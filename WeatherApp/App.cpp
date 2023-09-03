#include"Label.h"
#include"TextEntry.h"
#include"TextButton.h"

#include "StandardWindow.h"

#include "WeatherDrive.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	StandardWindow window("Weather App", 400, 400);

	Label l(window,"Enter a city name:", 10, 10, 200, 20);
	TextEntry city(window, 10, 30, 200, 20);
	TextButton b(window, "Get Weather", 10, 60, 200, 20);

	b.OnClick = [&city](auto& e) 
	{
		auto city_name = city.GetText();
		auto data = getWeatherData({city_name.c_str() , (long long)city_name.length()});
		std::string weather_desc = "Temp:" + std::to_string(data.r0) + "\nHumidity:" + std::to_string(data.r7) + "\nPressure:" + std::to_string(data.r6);
		MessageBoxA(NULL, weather_desc.c_str(), "Weather", MB_OK);
	};

	StandardWindow::MainLoop(&window);
	return 0;
}