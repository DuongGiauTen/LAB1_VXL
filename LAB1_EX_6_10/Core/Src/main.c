/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
uint16_t time_counter = 0;

void clearAllClock();
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
void run_led_test();
void turnOnAll();
void Ex10();
void ex6();
void ex7();
void ex8();
void ex9();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  //int counter = 0;



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  //ex6();
	  //ex7();
	  //ex8();
	  //ex9();
	  Ex6_7_8_9_10();




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

// Mảng hằng số để ánh xạ số từ 0-11 tới các chân GPIO từ PA4-PA15
// Cách này giúp code gọn gàng, không cần dùng if hoặc switch-case
const uint16_t led_pins[12] = {
    GPIO_PIN_4,  // Position 0 (12 o'clock)
    GPIO_PIN_5,  // Position 1 (1 o'clock)
    GPIO_PIN_6,  // Position 2 (2 o'clock)
    GPIO_PIN_7,  // Position 3 (3 o'clock)
    GPIO_PIN_8,  // Position 4 (4 o'clock)
    GPIO_PIN_9,  // Position 5 (5 o'clock)
    GPIO_PIN_10, // Position 6 (6 o'clock)
    GPIO_PIN_11, // Position 7 (7 o'clock)
    GPIO_PIN_12, // Position 8 (8 o'clock)
    GPIO_PIN_13, // Position 9 (9 o'clock)
    GPIO_PIN_14, // Position 10 (10 o'clock)
    GPIO_PIN_15  // Position 11 (11 o'clock)
};


//-------------------------------------------------------------------
// Exercise 7: Implement a function to turn off all 12 LEDs.
//-------------------------------------------------------------------
/**
  * @brief  Tắt tất cả 12 đèn LED trên đồng hồ.
  * @note   Sử dụng toán tử OR để gộp tất cả các chân và tắt trong một lệnh duy nhất.
  *         GPIO_PIN_SET sẽ đưa chân lên mức cao, tắt LED (giả sử LED nối với GND).
  * @retval None
  */
void clearAllClock() {
    HAL_GPIO_WritePin(GPIOA,
                      GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 |
                      GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
                      GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
                      GPIO_PIN_RESET);
}

void turnOnAll(){
    HAL_GPIO_WritePin(GPIOA,
                      GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 |
                      GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 |
                      GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
                      GPIO_PIN_SET);
}
//-------------------------------------------------------------------
// Exercise 8: Implement a function to turn on a specific LED.
//-------------------------------------------------------------------
/**
  * @brief  Bật một đèn LED tại vị trí được chỉ định.
  * @param  num: Số từ 0 đến 11 tương ứng với vị trí trên đồng hồ.
  * @note   Sử dụng mảng led_pins để lấy chân GPIO tương ứng.
  *         GPIO_PIN_RESET sẽ đưa chân về mức thấp, bật LED.
  * @retval None
  */
void setNumberOnClock(int num) {
    if (num >= 0 && num < 12) { // Kiểm tra đầu vào hợp lệ
        HAL_GPIO_WritePin(GPIOA, led_pins[num], GPIO_PIN_SET);
    }
}

//-------------------------------------------------------------------
// Exercise 9: Implement a function to turn off a specific LED.
//-------------------------------------------------------------------
/**
  * @brief  Tắt một đèn LED tại vị trí được chỉ định.
  * @param  num: Số từ 0 đến 11 tương ứng với vị trí trên đồng hồ.
  * @note   Sử dụng mảng led_pins để lấy chân GPIO tương ứng.
  *         GPIO_PIN_SET sẽ đưa chân lên mức cao, tắt LED.
  * @retval None
  */
void clearNumberOnClock(int num) {
    if (num >= 0 && num < 12) { // Kiểm tra đầu vào hợp lệ
        HAL_GPIO_WritePin(GPIOA, led_pins[num], GPIO_PIN_RESET);
    }
}

//-------------------------------------------------------------------
// Report 2: Implement a simple program to test the connection.
//-------------------------------------------------------------------
/**
  * @brief  Chạy chương trình kiểm tra, bật lần lượt từng LED.
  * @note   Hàm này sẽ chạy vô tận, mỗi LED sáng trong 200ms.
  * @retval None
  */
void run_led_test() {
    for (int i = 0; i < 12; i++) {
        clearAllClock(); // Xóa trạng thái cũ
        setNumberOnClock(i); // Bật LED hiện tại
        HAL_Delay(200); // Chỉ có 1 lệnh delay ở đây
    }
}

//-------------------------------------------------------------------
// Exercise 10: Integrate the whole system to display a clock.
//-------------------------------------------------------------------
/**
  * @brief  Chạy mô phỏng đồng hồ analog.
  * @note   Cập nhật và hiển thị kim giờ, phút, giây mỗi giây.
  *         Chỉ có 3 đèn LED sáng tại một thời điểm.
  * @retval None
  */
void ex6(){
	static int test = 0;
	HAL_GPIO_WritePin(GPIOA, led_pins[test], GPIO_PIN_SET);
	test++;
	if (test >= 12){
		test = 0;
	}
	HAL_Delay(1000);
}
void ex7(){
	static int test = 0;
	static int count = 0;
	HAL_GPIO_WritePin(GPIOA, led_pins[test], GPIO_PIN_SET);
	test++;
	count++;
	if (test >= 12){
		test = 0;

	}
	if (count >= 20){
		count = 0;
		clearAllClock();
	}
	HAL_Delay(200);

}
void ex8(){
	static int count = 0;

	setNumberOnClock(count);
	count++;
	if (count >= 12){
		count = 0;
	}
	HAL_Delay(200);
}
void ex9(){
	static int count = 0;
	turnOnAll();
	clearNumberOnClock(count);
	count++;
	if(count >= 12){
		count = 0;
		turnOnAll();
	}
	HAL_Delay(200);

}
void Ex10() {
    // Use 'static' so these variables retain their values between function calls
    // (in this case, between iterations of the while(1) loop)
    static int hour = 0, minute = 0, second = 0;

    // 1. Clear all LEDs before drawing the new hands
    clearAllClock();

    // 2. Display the three clock hands
    // Hour hand: `hour` already maps to positions 0-11
    setNumberOnClock(hour);
    // Minute hand: divide by 5 to convert 0-59 -> 0-11
    setNumberOnClock(minute / 5);
    // Second hand: divide by 5 to convert 0-59 -> 0-11
    setNumberOnClock(second / 5);

    // 3. Wait for a short period
    // NOTE: HAL_Delay(10) delays ~10 milliseconds. If you intend to wait 1 second,
    // use HAL_Delay(1000) instead.
    HAL_Delay(10);

    // 4. Update time for the next iteration
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        minute = 0;
        hour++;
    }
    if (hour >= 12) {
        hour = 0;
    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {

  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
