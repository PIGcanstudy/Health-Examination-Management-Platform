<template>
  <el-form :inline="true" :model="formInline" class="demo-form-inline">
    <el-form-item label="单位名称">
      <el-input v-model="formInline.user" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="信用代码">
      <el-input v-model="formInline.user" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="联系人">
      <el-input v-model="formInline.user" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="联系电话">
      <el-input v-model="formInline.user" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item>
      <el-button type="primary" @click="onSearch">搜索</el-button>
      <el-button plain @click="onReset">重置</el-button>
    </el-form-item>
  </el-form>
</template>

<script lang="ts" setup>
import { reactive } from 'vue'

const formInline = reactive({
  user: '',
  region: '',
  date: ''
})

/**
 * ？
 */
const onSearch = () => {
  console.log('search!')
}

/**
 * 将表单中的输入框清空
 * ？
 */
const onReset = () => {
  console.log('reset!')
}
</script>

<style>
.demo-form-inline .el-input {
  --el-input-width: 220px;
}

.demo-form-inline .el-select {
  --el-select-width: 220px;
}
</style>
