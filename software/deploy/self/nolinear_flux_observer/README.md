# STM32G4外设



## uart

通过vofa上传float数据

```c
uint8_t tx_buffer[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f};

while (1)
{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    temp += 0.01f;
    if (temp >= 6.28f)
    {
      temp = 0;
    }
		
	memcpy(tx_buffer,(uint8_t*)&temp,sizeof(temp));
	HAL_UART_Transmit_DMA(&huart3,(uint8_t*)tx_buffer,8);
    HAL_Delay(1);
}
```

float占4个字节，正好通过memcpy拷贝过去，又因为vofa float的帧尾是 0 0 0x80 0x7f，所以tx_buffer定义的大小为8



## adc

单端输入：就是正常的测量，一端在GND。



## 运放

运放的模式 standalone：增益是通过外部电阻来配置的



## 高级定时器TIM

internal clock division (CKD):影响滤波器和死区时间

![1698304283677](https://pic-1256068477.cos.ap-shanghai.myqcloud.com/img/1698304283677.png)

repetition counter寄存器：

![1698304391417](https://pic-1256068477.cos.ap-shanghai.myqcloud.com/img/1698304391417.png)

当我们设置为1的时候，1个周期的出发次数就变成了两次

### 死区时间计算

死区时间计算：假设dead time给了120，对应的寄存器是TIMx break and dead-time register (TIMx_BDTR)(x = 1, 8, 20)

120对应的hex:0111 1000，对应的事DT=DTG[7:0]* tdtg

![1698305085127](https://pic-1256068477.cos.ap-shanghai.myqcloud.com/img/1698305085127.png)

又因为ttds=1/定时器时钟

因为上面的ckd设置为了div2 ，所以ttds=1/80000000

所以120/80000000=0.0000015s = 1500ns



### tim触发adc

![1698306323269](https://pic-1256068477.cos.ap-shanghai.myqcloud.com/img/1698306323269.png)

这里的pluse相当于直接设定占空比了，在mode2模式下的99%，低电平占据99%的时间



## TIM ADC OPAMP级联

![image-20231027091934436](https://pic-1256068477.cos.ap-shanghai.myqcloud.com/img/image-20231027091934436.png)

当下桥臂打开的中心点，去采样电流，接近于完全中心点，但是没有设置到最大值
