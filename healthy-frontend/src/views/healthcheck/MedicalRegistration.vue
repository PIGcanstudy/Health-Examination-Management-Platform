<!-- eslint-disable prettier/prettier -->
<!-- 体检登记 -->
<template>
  <el-container style="height: 100vh;">
    <!-- 侧边栏 -->
    <el-aside :style="{maxWidth: isCollapsed ? '64px' : '300px'}">
      <!-- 伸缩按钮 -->
      <el-icon style="cursor: pointer; width: 20px;" @click="isCollapsed = !isCollapsed"><ArrowRightBold /></el-icon>
      <PeopleList
        :style="isCollapsed ? 'display: none;' : 'min-width: 300px;'"
        :title="title"
        :checkbox-item="checkboxItem"
        :is-date-visible="isDateVisible"
        :external-form-items="formConfig.formItems"
      />
    </el-aside>

    <!-- 主要内容 -->
    <el-main>
      <MedicalInfo
        :current-progress="currentProgress"
        :progress-steps="progressSteps"
        :person-info="personInfo"
      />
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import { ArrowRightBold } from '@element-plus/icons-vue'
// PeopleList的变量
const title = ref('人员查询')
const checkboxItem = ref(['未登记', '已登记'])
const isDateVisible = ref(false)
const formConfig = ref({
  formItems: [
    {
      type: 'input',
      name: '',
      placeholder: '请输入身份证号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入体检编号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入单位名称'
    }
  ]
})
// MedicalInfo的变量
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const personInfo = ref({
  physical_id: '2202401120016',
  id_card: '510521199304017011',
  person_name: 'test-rom',
  sex: '男',
  age: '30',
  physical_type: '健康体检',
  mobile: '18980504604',
  unit_name: 'test-rom',
  marry_type: '',
  type_name: ''
})
// 本界面变量及函数
const isCollapsed = ref(false)
</script>
