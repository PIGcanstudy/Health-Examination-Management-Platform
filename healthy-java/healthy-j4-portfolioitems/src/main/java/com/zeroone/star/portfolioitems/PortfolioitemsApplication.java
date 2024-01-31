package com.zeroone.star.portfolioitems;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.ComponentScan;

/**
 * <p>
 * 描述：服务器启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@MapperScan("com.zeroone.star.portfolioitems.mapper")
@SpringBootApplication
@EnableDiscoveryClient
public class PortfolioitemsApplication {

    public static void main(String[] args) {
        SpringApplication.run(PortfolioitemsApplication.class, args);
    }

}
