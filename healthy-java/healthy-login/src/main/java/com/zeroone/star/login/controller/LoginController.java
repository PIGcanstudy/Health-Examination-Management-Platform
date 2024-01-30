package com.zeroone.star.login.controller;

import cn.hutool.captcha.CaptchaUtil;
import cn.hutool.captcha.LineCaptcha;
import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.codec.Base64;
import cn.hutool.core.io.FastByteArrayOutputStream;
import cn.hutool.core.util.IdUtil;
import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.login.service.UserService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.time.Duration;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Api(tags = "login")
public class LoginController implements LoginApis {
    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Resource
    RedisTemplate redisTemplate;

    @Resource
    UserService userService;

    @Autowired
    private CaptchaService captchaService;

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        //TODO:未实现验证码验证
        CaptchaVO captchaVO = new CaptchaVO();
        captchaVO.setCaptchaVerification(loginDTO.getCode());
        ResponseModel response = captchaService.verification(captchaVO);
        if (!response.isSuccess()) {
            //验证码校验失败，返回信息告诉前端
            //repCode  0000  无异常，代表成功
            //repCode  9999  服务器内部异常
            //repCode  0011  参数不能为空
            //repCode  6110  验证码已失效，请重新获取
            //repCode  6111  验证失败
            //repCode  6112  获取验证码失败,请联系管理员
        }
        //账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", loginDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        //获取验证码
        String code = loginDTO.getCode();
        if (!Objects.equals(redisTemplate.opsForValue().get(loginDTO.getClientId()), code)) {
            //错误则返回前端并提示
//            return oAuthService.postDenyToken(params);
            return oAuthService.postAccessToken(params);
        }
        //验证成功则清除redis内的验证码缓存
        redisTemplate.delete(loginDTO.getClientId());

        return oAuthService.postAccessToken(params);
        //TODO:未实现认证成功后如何实现注销凭证（如记录凭证到内存数据库）
    }
    
    @ApiOperation(value = "获取验证码")
    @GetMapping("getCode")
    @Override
    public JsonVO<LoginDTO> getCode() {
        LineCaptcha lineCaptcha = CaptchaUtil.createLineCaptcha(200, 100);
        String verify = IdUtil.simpleUUID();
        //图形验证码写出到文件流
        FastByteArrayOutputStream os = new FastByteArrayOutputStream();
        lineCaptcha.write(os);
        String code = lineCaptcha.getCode();
        //缓存一分钟的验证码
        redisTemplate.opsForValue().set(verify, code, Duration.ofMinutes(1));


        ConcurrentHashMap<String, String> map = new ConcurrentHashMap<>(5);
        //验证码对应的redis上的uuid
        map.put("uuid", verify);
        //图片上的验证码
        map.put("code", code);
        //将图片转换成输出流传到前端上
        map.put("img", Base64.encode(os.toByteArray()));
        LoginDTO dto = new LoginDTO();
        BeanUtil.copyProperties(code, dto);
        return JsonVO.success(dto);
    }

    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO) {
        //TODO:未实现注销凭证验证
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", oauth2TokenDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("refresh_token", oauth2TokenDTO.getRefreshToken());
        return oAuthService.postAccessToken(params);
    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            //TODO:这里需要根据业务逻辑接口，重新实现
            LoginVO loginVO = userService.getUserById(currentUser.getId());
//            LoginVO vo = new LoginVO();
//            BeanUtil.copyProperties(currentUser, vo);
            return JsonVO.success(loginVO);
        }
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        //TODO:登出逻辑，需要配合登录逻辑实现
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        String token=null;
        if (servletRequestAttributes != null) {
            HttpServletRequest request = servletRequestAttributes.getRequest();
            String authorizationHeader = request.getHeader("Authorization");
            if (authorizationHeader != null && authorizationHeader.startsWith("Bearer ")) {
                token = authorizationHeader.replace("Bearer ", "");
            }
        }

        String tokenKeyInRedis = RedisConstant.USER_TOKEN + ":" + token;
        if (Boolean.FALSE.equals(redisTemplate.hasKey(tokenKeyInRedis))) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), ResultStatus.UNAUTHORIZED.getMessage());
        }
        redisTemplate.delete(tokenKeyInRedis);
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), "退出成功");
    }

    @Resource
    IMenuService menuService;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        // TODO:未实现根据实际数据库设计业务逻辑，下面逻辑属于示例逻辑
        //1 获取当前用户
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), e.getMessage());
        }

        //2 获取当前用户拥有的菜单
        try {
            List<MenuTreeVO> menus = menuService.listMenuByRoleName(currentUser.getRoles());
            return JsonVO.success(menus);
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }

    }
}
