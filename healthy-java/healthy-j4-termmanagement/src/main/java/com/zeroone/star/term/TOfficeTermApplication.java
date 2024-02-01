package com.zeroone.star.term;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author
 * @version 1.0.0
 */
@SpringBootApplication
@EnableDiscoveryClient
public class TOfficeTermApplication {

    public static void main(String[] args) {
        SpringApplication.run(TOfficeTermApplication.class, args);
    }

}
