<!-- 体检报告 -->
<template>
  <div class="container">
    <div class="left-main">
      <Head name="人员信息" style="font-size: 15px" />
      <el-form ref="formRef" :model="form">
        <div v-if="isShowInput">
          <el-form-item prop="serialNumber">
            <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
          </el-form-item>
          <el-form-item prop="workplace">
            <el-select v-model="form.workplace" placeholder="请输入单位名称" clearable>
              <el-option label="未审核" :value="unreviewed" />
              <el-option label="已审核" :value="reviewed" />
            </el-select>
          </el-form-item>
        </div>
        <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
          >{{ isShowInput ? '收起' : '展开' }}
          <el-icon v-show="isShowInput == true"><ArrowUp /></el-icon>
          <el-icon v-show="isShowInput == false"><ArrowDown /></el-icon>
        </el-button>
      </el-form>
    </div>
    <div class="right-main">
      <Head name="检查详情" style="font-size: 15px" />
    </div>
  </div>
</template>

<script setup>
import { ref,onMounted } from 'vue'
import Head from '@/components/head/Head.vue'
import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'
const temp = ref()
onMounted(()=>{
  console.log(temp.value)
})
// 表单验证逻辑
const form = ref({
  serialNumber: '',
  workplace: '',

})

// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}
</script>

<style lang="scss" scoped>
.container {
  display: flex;
}
.left-main {
  width: 65%;
  /* 可以添加更多样式，如padding, margin等 */
}
.right-main {
  width: 35%;
  /* 可以添加更多样式，如padding, margin等 */
}
</style>
