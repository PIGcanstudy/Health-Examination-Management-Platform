<!-- 系统配置 -->
<template>
  <el-radio-group v-model="tabPosition" style="margin-bottom: 30px">
    <el-radio-button label="top">top</el-radio-button>
    <el-radio-button label="right">right</el-radio-button>
    <el-radio-button label="bottom">bottom</el-radio-button>
    <el-radio-button label="left">left</el-radio-button>
  </el-radio-group>

  <el-tabs :tab-position="tabPosition" style="height: 700x" class="demo-tabs">
    <el-tab-pane label="文件对象存储配置"><!-- 表单 -->
      <div>文件对象存储配置</div>
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="服务提供商" class="bold-label">
      <el-select v-model="formInline.fwtgs" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="accessKey" class="bold-label">
  <el-input v-model="formInline.acckey"  placeholder="请输入accessKey"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="formInline.seckey"  placeholder="请输入secretKey"/>
</el-form-item>
<el-form-item  label="bucket空间" class="bold-label">
  <el-input v-model="formInline.bucket"   placeholder="请输入bucket空间名"/>
</el-form-item>
<el-form-item  label="endpoint域名" class="bold-label">
  <el-input v-model="formInline.endpointym"   class="input-with-select" placeholder="请输入空间访问域名">
    <template #prepend>
        <el-select v-model="select" placeholder="Select" style="width: 115px">
          <el-option label="Restaurant" value="1" />
          <el-option label="Order No." value="2" />
          <el-option label="Tel" value="3" />
        </el-select>
      </template>
  </el-input>
</el-form-item>
</el-form>

          <el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存并启用
          </el-button>
    </el-tab-pane>

    <el-tab-pane label="短信配置">
      <div>短信配置</div>
     <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="服务提供商" class="bold-label">
      <el-select v-model="dxpz.fwtgs" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="accessKey" class="bold-label">
  <el-input v-model="dxpz.acckey"  placeholder="请输入accessKey"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="dxpz.seckey"  placeholder="请输入secretKey"/>
</el-form-item>
<el-form-item  label="短信签名" class="bold-label">
  <el-input v-model="dxpz.dxqm"   placeholder="请输入短信签名,例如XBoot"/>
</el-form-item>
 <el-form-item  label="使用场景" class="bold-label">
      <el-select v-model="dxpz.sycj" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="模板CODE" class="bold-label">
  <el-input v-model="dxpz.mbCode"  placeholder="请输入场景对应短信模板CODE，例如SMS_123456789"/>
</el-form-item>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>

    <el-tab-pane label="邮件配置">
      <idv>邮件配置</idv>
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-col :span="24">
        <el-form-item  label="服务提供商" class="bold-label">
      <el-select v-model="dxpz.fwtgs" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
</el-col>
<el-form-item  label="accessKey" class="bold-label">
  <el-input v-model="dxpz.acckey"  placeholder="请输入accessKey"/>
</el-form-item>
<el-form-item  label="secretKey" class="bold-label">
  <el-input type="password" show-password v-model="dxpz.seckey"  placeholder="请输入secretKey"/>
</el-form-item>
<el-form-item  label="短信签名" class="bold-label">
  <el-input v-model="dxpz.dxqm"   placeholder="请输入短信签名,例如XBoot"/>
</el-form-item>
 <el-form-item  label="使用场景" class="bold-label">
      <el-select v-model="dxpz.sycj" class="m-2" placeholder="请选择" size="large" style="width: 240px">
    <el-option v-for="item in props.ksmcsw " :key="item" :label="item.label" :value="item.value"/>
  </el-select>
</el-form-item>
<el-form-item  label="模板CODE" class="bold-label">
  <el-input v-model="dxpz.mbCode"  placeholder="请输入场景对应短信模板CODE，例如SMS_123456789"/>
</el-form-item>
</el-form>

<el-button
            type="primary"
            @click="onSubmit();resetFrom()"
          >
            保存更改
          </el-button>
    </el-tab-pane>
    <el-tab-pane label="Vaptcha验证码">Vaptcha验证码</el-tab-pane>
    <el-tab-pane label="禁用词管理">禁用词管理</el-tab-pane>
    <el-tab-pane label="系统公告配置">系统公告配置</el-tab-pane>
    <el-tab-pane label="其他配置">其他配置</el-tab-pane>
  </el-tabs>
</template>
<script lang="ts" setup>
import { ref,reactive } from 'vue'

const props = defineProps({
  ksmcsw: {
    type: Array,
    default: () => []
  },
  tjlxsw: {
    type: Array,
    default: () => []
  },
  sylxsw: {
    type: Array,
    default: () => []
  },
  whyssw: {
    type: Array,
    default: () => []
  },
  zgztsw: {
    type: Array,
    default: () => []
  }
})

// 文件对象存储配置数据字段
const formInline = reactive({
  fwtgs: '',
  acckey: '',
  seckey: '',
  bucket:'',
  endpointym:''
})

// 短信配置数据字段
const dxpz = reactive({
  fwtgs: '',
  acckey: '',
  seckey: '',
  dxqm:'',
  sycj:'',
  mbCode:''
})


// 提交表单
const onSubmit = () => {
  
}

// 清空表单
const resetFrom = () => {
 // 将表单中的输入框清空
 for (const key in formInline) {
  formInline[key] = ''
  }
}

const tabPosition = ref('left')
</script>
<style>
.demo-tabs > .el-tabs__content {
  padding: 32px;
  color: #6b778c;
  font-size: 32px;
  font-weight: 600;
}

.el-tabs--right .el-tabs__content,
.el-tabs--left .el-tabs__content {
  height: 100%;
}
</style>
