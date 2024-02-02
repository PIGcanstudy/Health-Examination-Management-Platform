<!-- 个人中心 -->
<template>
  <el-card>
    <el-tabs tab-position="left" class="demo-tabs">
      <el-tab-pane label="基本信息">
        <h1>基本信息</h1>
        <el-form :model="baseFormation" :label-position="labelPosition" label-width="100px">
          <el-form-item label="登录账号:">
            <span>admin</span>
          </el-form-item>
          <el-form-item label="用户头像:"> 文件上传 </el-form-item>
          <el-form-item label="性别">
            <el-select v-model="baseFormation.gender" style="width: 220px">
              <el-option v-for="item in genderOptions" :key="item" :label="item.label" :value="item.value"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="生日:">
            <el-date-picker v-model="baseFormation.birthday" type="date" />
          </el-form-item>
          <el-form-item label="所在省市:">
            <el-select style="width: 220px"></el-select>
          </el-form-item>
          <el-form-item label="个人简介:">
            <el-input v-model="baseFormation.resume" type="textarea" style="width: 220px"></el-input>
          </el-form-item>
          <el-form-item label="所属部门:"></el-form-item>
          <el-form-item label="用户类型:">
            <span>管理员</span>
          </el-form-item>
          <el-form-item label="签字文件"> 文件上传 </el-form-item>
        </el-form>
      </el-tab-pane>
      <el-tab-pane label="安全设置">
        <h1>安全设置</h1>
        <div class="content">
          <div class="item">
            <div class="text">
              <div class="topic">账户密码</div>
              <div class="bottom">当前密码强度: <span style="color: rgb(250, 173, 20)">中</span></div>
            </div>

            <el-button link class="button">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">绑定手机</div>
              <div class="bottom">已绑定手机: <span>18782059031</span></div>
            </div>
            <el-button link class="button">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">绑定邮箱</div>
              <div class="bottom">已绑定邮箱 <span>admin@exrick.cn</span></div>
            </div>
            <el-button link class="button">修改</el-button>
          </div>
          <el-divider></el-divider>
          <div class="item">
            <div class="text">
              <div class="topic">密保问题</div>
              <div class="bottom">未设置密保问题,密保问题可有效保护账户安全</div>
            </div>
            <el-button link class="button">暂不支持设置</el-button>
          </div>
          <el-divider></el-divider>
        </div>
      </el-tab-pane>
      <el-tab-pane label="第三方账号绑定">
        <h1>第三方账号绑定</h1>
      </el-tab-pane>
      <el-tab-pane label="消息通知">
        <h1>消息通知</h1>
        <div class="message">
          <div class="system">
            <div class="header">系统消息</div>
            <div class="bottom">系统消息将以站内信的形式通知</div>
          </div>
          <el-switch v-model="systemMessages" active-text="开" inactive-text="关" inline-prompt></el-switch>
        </div>
        <el-divider />
      </el-tab-pane>
    </el-tabs>
  </el-card>
  <el-drawer v-model="drawer" title="修改密码" label-position="drawerLabel">
    <el-form v-model="remakePw" style="margin-top: 15px">
      <el-form-item label="*原密码" label-width="100">
        <el-input v-model="remakePw.oldPassword" placeholder="请输入现在使用的密码"></el-input>
      </el-form-item>
      <el-form-item label="*新密码" label-width="100">
        <el-input v-model="remakePw.newPassword" placeholder="请输入新密码,长度为6-20个字符"></el-input>
      </el-form-item>
      <el-form-item label="*确认新密码" label-width="100">
        <el-input v-model="remakePw.confirm" placeholder="请再次输入新密码"></el-input>
      </el-form-item>
    </el-form>
  </el-drawer>
</template>

<script lang="ts" setup>
import { ref, reactive } from 'vue'

// 基本信息表单---label位置
const labelPosition = ref('left')

// 修改密码---label位置
const drawerLabel = ref('top')

// 基本信息表单
const baseFormation = reactive({
  account: '',
  photo: '',
  userName: '',
  gender: '',
  birthday: '',
  locationCity: '',
  locationStreet: '',
  resume: '',
  department: '',
  userType: '',
  document: ''
})

// 基本信息表单---性别选项
const genderOptions = ref([
  {
    value: '男',
    label: '男'
  },
  {
    value: '女',
    label: '女'
  }
])

// 抽屉显隐
const drawer = ref(true)

// 修改密码表单
const remakePw = reactive({
  oldPassword: '',
  newPassword: '',
  confirm: ''
})

// 消息通知---系统消息开关
const systemMessages = ref(true)
</script>

<style lang="scss" scoped>
// 通用设置
h1 {
  margin-bottom: 15px;
}

// 安全设置
.item {
  display: flex;
  justify-content: space-between;
  .button {
    color: rgb(45, 140, 240);
  }
  .topic {
    color: rgba(0, 0, 0, 0.65);
    margin-bottom: 4px;
    font-size: 14px;
  }
  .bottom {
    color: rgba(0, 0, 0, 0.45);
    font-size: 14px;
  }
}

// 消息通知
.message {
  display: flex;
  justify-content: space-between;
  .header {
    font-size: 14px;
    color: rgba(0, 0, 0, 0.65);
  }
  .bottom {
    color: rgba(0, 0, 0, 0.45);
    font-size: 14px;
  }
}
</style>
