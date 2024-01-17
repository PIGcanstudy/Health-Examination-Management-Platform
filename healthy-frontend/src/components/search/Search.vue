<template>
  <div class="top">
    <el-form :inline="true" :model="formInline">
      <el-form-item label="单位名称" class="bold-label">
        <el-input v-model="formInline.name" placeholder="请输入" clearable />
      </el-form-item>
      <el-form-item label="信用代码" class="bold-label">
        <el-input v-model="formInline.credit" placeholder="请输入" clearable />
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
  </div>
</template>

<script setup>
import { reactive } from 'vue'
import { Search } from '@element-plus/icons-vue'

const formInline = reactive({
  name: '',
  credit: '',
  contact: '',
  phone: ''
})

let props = defineProps(['sendToSearch', 'sendToReset'])

/**
 * 将输入框的值传给表格组件
 */
const onSearch = () => {
  console.log('search!')
  const data = formInline
  for (let each in data) {
    if (each === '') {
      each === '--'
    }
  }
  props.sendToSearch(data)
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
  // parent
  props.sendToReset()
}
</script>

<style lang="scss" scoped>
.top {
  border-bottom: 2px dashed rgb(224, 224, 238);

  .el-form {
    .el-form-item {
      .el-input {
        --el-input-width: 150px;
      }
    }
  }
}
</style>
