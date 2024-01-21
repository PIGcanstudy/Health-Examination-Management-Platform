<!-- 登录页面 -->
<template>
  <!-- 测试样式操作区域 -->
  <div class="container">
    <div class="top-bar">
      <!-- <img src="@\assets\login\logo.webp" alt="" /> -->
      <div class="logo">logo</div>
      <!-- <div class="navigation">
      <a href="#">关于</a>
      <a href="#">联系我们</a>
    </div> -->
    </div>

    <div class="color">
      <div class="c1"></div>
      <div class="c2"></div>
      <div class="c3"></div>
    </div>

    <el-row class="main">
      <el-col :span="12">
        <div class="left">零壹健康体检管理系统</div>
      </el-col>
      <el-col :span="8" :offset="1">
        <el-card class="box-card">
          <h2>登录</h2>
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
      </el-col>
    </el-row>
  </div>

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
import TestTable from '@/components/search/TestTable.vue'

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

<style lang="scss" scoped>
/* 原代码 */
/* .box-card {
  width: 480px;
  margin: 50px auto;
  padding: 20px;
} */

/* 以下是修改后的样式 */
.box-card {
  width: 440px;
  margin: 50px auto;
  padding: 20px;
  border-radius: 4%;
  opacity: 1;
}

.top-bar {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  padding: 24px 100px;
  display: flex;
  justify-content: space-between;
  align-content: center;
  z-index: 99;
  opacity: 3;
}

.logo {
  font-size: 2em;
  color: #fff;
  user-select: none;
}

.navigation a {
  position: relative;
  font-size: 1.1em;
  color: rgb(100, 97, 97);
  text-decoration: none;
  padding: 10px;
  margin: 24px;
}

.navigation a::after {
  content: '';
  position: absolute;
  left: 0;
  bottom: -3px;
  width: 100%;
  height: 3px;
  color: rgb(100, 97, 97);
  border-radius: 5px;
  transform: scaleX(0);
  transition: transform 0.5s;
}

.navigation a:hover::after {
  transform: scaleX(1);
  transform-origin: center;
}

.container {
  min-height: 100vh;
  background: linear-gradient(to bottom, #f1f4f9, #dff1ff);
}

.color {
  position: absolute;
  filter: blur(150px);
}
.c1 {
  top: -50px;
  right: 100px;
  width: 300px;
  height: 300px;
  background: #b8f0b6;
}
.c2 {
  top: -150px;
  left: 150px;
  width: 400px;
  height: 350px;
  background: #efaacd;
}
.c3 {
  top: 50px;
  right: 100px;
  width: 300px;
  height: 300px;
  background: #00d2ff;
}
.main {
  display: flex;
  justify-content: center;
  align-items: center;
  background: url('@/assets/login/bg-img.png') no-repeat;
  min-height: 100vh;
  background-position: 600px;
  background-size: 550px;
}

.left {
  position: relative;
  top: -260px;
  left: 80px;
  font-size: 36px;
  font-weight: 600;
}

.box-card {
  h2 {
    font-size: 1.6em;
    color: #636a71;
    margin: 14px;
  }
}
</style>
