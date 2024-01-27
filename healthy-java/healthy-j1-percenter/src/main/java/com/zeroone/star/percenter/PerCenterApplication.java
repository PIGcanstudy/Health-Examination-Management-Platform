package com.zeroone.star.percenter;

import com.zeroone.star.project.components.jwt.JwtComponent;
import com.zeroone.star.project.components.user.UserHolder;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.Bean;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

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
@EnableDiscoveryClient
public class PerCenterApplication {

    public static void main(String[] args) {
        SpringApplication.run(PerCenterApplication.class, args);
    }

    @Bean
    public UserHolder userHolder(){
        return new UserHolder();
    }

    @Bean
    public JwtComponent jwtComponent(){
        return  new JwtComponent();
    }

    @Bean
    public PasswordEncoder passwordEncoder(){
        return new BCryptPasswordEncoder();
    }

}
