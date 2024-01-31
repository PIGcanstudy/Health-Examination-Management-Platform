<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-31 17:10:36
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-31 20:44:30
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\basicdata\SampleLibrary\SampleLibraryForm.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div class="SampleLibraryForm">
    <!-- 原代码 -->
    <!-- <el-dialog v-model="dialogVisible" title="新增" width="50%" :before-close="handleClose"> -->

    <el-dialog v-model="dialogVisible" width="50%" :before-close="handleClose">
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>

      <template #default>
        <el-col>
          <el-form ref="basicFormRef" :model="basicForm" :rules="rules" inline>
            <el-form-item label="名称" :label-width="labelWidth">
              <el-input v-model="basicForm.sampleName" placeholder="请输入名称" style="width: 200px"></el-input>
            </el-form-item>
            <el-form-item label="条码份数" :label-width="labelWidth">
              <el-select v-model="basicForm.barcodeCopies" style="width: 200px"></el-select>
            </el-form-item>
            <el-form-item label="规格" :label-width="labelWidth">
              <el-input v-model="basicForm.specification" placeholder="请输入规格" style="width: 200px"></el-input>
            </el-form-item>
            <el-form-item label="是否采血" :label-width="labelWidth">
              <el-radio-group v-model="basicForm.isBloodSampling" style="width: 200px">
                <el-radio label="是" />
                <el-radio label="否" />
              </el-radio-group>
            </el-form-item>
            <el-form-item label="标本代码" :label-width="labelWidth">
              <el-select v-model="basicForm.sampleCode" style="width: 200px"></el-select>
            </el-form-item>
            <el-form-item label="排序" :label-width="labelWidth">
              <el-select v-model="basicForm.rank" style="width: 200px"></el-select>
            </el-form-item>
            <el-form-item label="是否打印" :label-width="labelWidth">
              <el-radio-group v-model="basicForm.isPrint" style="width: 200px">
                <el-radio label="是" />
                <el-radio label="否" />
              </el-radio-group>
            </el-form-item>
            <el-form-item label="关联码" :label-width="labelWidth">
              <el-select v-model="basicForm.associationCode" style="width: 200px"></el-select>
            </el-form-item>
            <el-form-item label="容量" :label-width="labelWidth">
              <el-input v-model="basicForm.capacity" style="width: 200px"></el-input>
            </el-form-item>
          </el-form>
        </el-col>
      </template>

      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="dialogVisible = false">提交</el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>

<script setup>
import { ref } from 'vue'
const dialogVisible = ref(false)
const labelWidth = '120px'
// 基础信息表单
const basicForm = ref({
  sampleName: '',
  barcodeCopies: '',
  specification: '',
  sampleCode: '',
  rank: '',
  isPrint: '',
  associationCode: '',
  capacity: ''
})

const props = defineProps({
  handleSubmit: {
    type: Function,
    default: () => {
      console.log('submit')
    }
  },
  title: {
    type: String,
    default: '新增'
  }
})

const basicFormRef = ref()
const rules = ref({
  sampleName: [{ required: true, message: '名称不能为空!', trigger: 'change' }],
  specification: [{ required: true, message: '规格不能为空!', trigger: 'change' }],
  sampleCode: [{ type: 'date', required: true, message: '标本代码不能为空!', trigger: 'change' }]
})

defineExpose({
  dialogVisible,
  basicForm
})
</script>
