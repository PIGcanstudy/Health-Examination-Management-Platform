<!-- 登录页面 -->
<template>
  <!-- 测试样式操作区域 -->
  <div class="top-bar" style="display: flex; height: 80px">顶部栏</div>
  <el-row class="login-page">
    <el-col :span="14" class="bgImg">
      <div class="left-part" style="align-items: center; justify-content: center">
        <h1>01健康体检系统</h1>
      </div>
    </el-col>
    <el-col :span="6" :offset="1" class="loginForm">
      <div class="mask-layer" style="margin: 230px 44px">
        <el-card class="box-card">
          <h2 style="padding-left: 16px; margin: 24px 0">登录</h2>
          <el-form :model="formData" status-icon label-width="60px">
            <el-form-item label="账号" prop="username">
              <el-input v-model="formData.username"></el-input>
            </el-form-item>
            <el-form-item label="密码" prop="password">
              <el-input v-model="formData.password" type="password"></el-input>
            </el-form-item>
            <el-form-item style="margin-top: 22px">
              <el-button type="primary" @click="submitForm()">登录</el-button>
            </el-form-item>
          </el-form>
          <!-- TODO[TEST_CODE]: 测试代码后期发布需要删除 -->
          <router-link to="/sample">进入示例演示页面</router-link>
        </el-card>
      </div>
    </el-col>
  </el-row>

  <!-- 项目原代码-------------------------------------------------- -->
  <!-- <el-card class="box-card">
    <el-form :model="formData" status-icon label-width="60px">
      <el-form-item label="账号" prop="username">
        <el-input v-model="formData.username"></el-input>
      </el-form-item>
      <el-form-item label="密码" prop="password">
        <el-input v-model="formData.password" type="password"></el-input>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" @click="submitForm()">登录</el-button>
      </el-form-item>
    </el-form> -->
  <!-- TODO[TEST_CODE]: 测试代码后期发布需要删除 -->
  <!-- <router-link to="/sample">进入示例演示页面</router-link>
  </el-card> -->

  <!-- 验证码组件 -->
  <Verify ref="verify" mode="pop" :captcha-type="captchaType" :img-size="{ width: '400px', height: '200px' }" @success="handleSuccess"></Verify>
  <!-- 项目原代码-------------------------------------------------- -->
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
import { ref, reactive } from 'vue'
import { login } from '@/apis/login'
import { ElMessage } from 'element-plus'
import { useRouter } from 'vue-router'

// 获取router对象
const $router = useRouter()

// 定义登录数据对象
const formData = reactive({
  username: '',
  password: ''
})

/**
 * 执行登录
 * @param code 验证码字符串
 */
function doLogin(code) {
  // 发送登录请求
  login(
    {
      ...formData,
      clientId: import.meta.env.VITE_CLIENT_ID,
      code: code
    },
    () => {
      // 跳转到首页
      $router.push('/home')
      // 登录成功提示
      ElMessage.success('登录成功，前往首页')
    },
    () => {
      ElMessage.error('账号或密码错误')
    }
  )
}

// 定义登录提交函数
function submitForm() {
  //TODO[TEST_CODE]:测试直接进入主界面
  //$router.push('/home')
  doLogin('res.captchaVerification')

  // 弹出验证码框
  //useVerify('blockPuzzle')
}

// 验证码组件引用
const verify = ref(null)

// 验证码类型
const captchaType = ref('')

/**
 * 弹出验证码框
 * @param type 验证码类型 blockPuzzle滑块验证 clickWord点击文字验证
 */
function useVerify(type) {
  captchaType.value = type
  verify.value.show()
}

/**
 * 验证码验证通过执行登录二次验证逻辑
 * @param res 验证通过信息
 */
function handleSuccess(res) {
  //TODO[TEST_CODE]:测试调用二次验证
  // Request.requestForm(
  //   Request.POST,
  //   '/login',
  //   { captchaVerification: res.captchaVerification },
  //   { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  // )
  //   .then((res) => {
  //     console.log(res)
  //     if (res.data.repCode === '0000') {
  //       // 跳转到首页
  //       $router.push('/home')
  //       // 登录成功提示
  //       ElMessage.success('登录成功，前往首页')
  //       return
  //     }
  //     ElMessage.error('账号或密码错误')
  //   })
  //   .catch((res) => {
  //     console.log(res)
  //     ElMessage.error('账号或密码错误')
  //   })

  doLogin(res.captchaVerification)
}
</script>

<style>
.box-card {
  width: 480px;
  margin: 50px auto;
  padding: 20px;
  /* 添加德阳市，暂存，后续改进 */
  border-radius: 4%;
}
</style>
