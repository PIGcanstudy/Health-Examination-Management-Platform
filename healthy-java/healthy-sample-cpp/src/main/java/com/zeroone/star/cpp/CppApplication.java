package com.zeroone.star.cpp;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;

/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient  // 允许服务注册到Nacos
@EnableFeignClients     // 允许使用Feign调用其他服务
public class CppApplication {

    public static void main(String[] args) {
        SpringApplication.run(CppApplication.class, args);
    }

}
