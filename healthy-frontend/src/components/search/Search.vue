<template>
  <el-form :inline="true" :model="formInline" class="demo-form-inline">
    <el-form-item label="单位名称" class="bold-label">
      <el-input v-model="formInline.name" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="信用代码" class="bold-label">
      <el-input v-model="formInline.code" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="联系人" class="bold-label">
      <el-input v-model="formInline.contact" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item label="联系电话" class="bold-label">
      <el-input v-model="formInline.phone" placeholder="请输入" clearable />
    </el-form-item>
    <el-form-item>
      <el-button type="primary" :icon="Search" @click="onSearch">搜索</el-button>
      <el-button plain @click="onReset">重置</el-button>
    </el-form-item>
  </el-form>
</template>

<script setup>
import { reactive } from 'vue'
import { Search } from '@element-plus/icons-vue'

const formInline = reactive({
  name: '',
  code: '',
  contact: '',
  phone: ''
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
  // 将表单中的输入框清空
  for (const key in formInline) {
    formInline[key] = ''
  }
}
</script>

<style>
.demo-form-inline .el-input {
  --el-input-width: 220px;
}

.bold-label .el-form-item__label {
  font-weight: bold;
}
</style>
